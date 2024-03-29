﻿#pragma once

#include "signal.h" // NOLINT (deprecated header)

//! @file

namespace sgd {

struct ObjectType {
	String name;
	ObjectType* const super;
	ObjectType* const succ;

	ObjectType(const char* name, ObjectType* super) noexcept : name(name), super(super), succ(g_allTypes) {
		g_allTypes = this;
	}

	constexpr bool extends(const ObjectType* that) const {
		for (auto type = this; type; type = type->super) {
			if (type == that) return true;
		}
		return false;
	}

	static inline ObjectType* allTypes() {
		return g_allTypes;
	}

	int instanceCount() const {
#if SGD_CONFIG_DEBUG
		return m_instanceCount;
#else
		return 0;
#endif
	}

private:
	static inline ObjectType* g_allTypes;
#if SGD_CONFIG_DEBUG
	friend struct DebugInstanceCounter;
	int m_instanceCount{};
#endif
};

#if SGD_CONFIG_DEBUG
struct DebugInstanceCounter {
	ObjectType* const type;
	explicit DebugInstanceCounter(ObjectType* type) : type(type) {
		++type->m_instanceCount;
	}
	~DebugInstanceCounter() {
		--type->m_instanceCount;
	}
};
#define SGD_DEBUG_INSTANCE_COUNTER DebugInstanceCounter _sgdDebugInstanceCounter{&_sgdStaticType};
#else
#define SGD_DEBUG_INSTANCE_COUNTER
#endif

// clang-format off
#define SGD_OBJECT_TYPE(NAME, SUPER) \
	static inline ObjectType _sgdStaticType{#NAME, SUPER::staticType()}; \
	SGD_DEBUG_INSTANCE_COUNTER \
	static inline constexpr ObjectType* staticType(){return &_sgdStaticType;} \
	ObjectType* dynamicType() const override {return &_sgdStaticType;}      \
	using Super = SUPER;
// clang-format on

struct Object;
using CObject = const Object;

struct Object {
	// clang-format off
	static inline ObjectType _sgdStaticType{"Object", nullptr};
	SGD_DEBUG_INSTANCE_COUNTER
	// clang-format on

	Object() = default;

	virtual ~Object() {
		deleted.emit();
	}

	Signal<> deleted;

	static inline constexpr ObjectType* staticType() {
		return &_sgdStaticType;
	}

	virtual ObjectType* dynamicType() const {
		return staticType();
	}

	bool is(ObjectType* type) const {
		return dynamicType()->extends(type);
	}

	template <class T> bool is() const {
		return dynamicType()->extends(T::staticType());
	}

	template <class T> T* as() {
		SGD_ASSERT(is<T>());
		return static_cast<T*>(this);
	}

	template <class T> const T* as() const {
		SGD_ASSERT(is<T>());
		return static_cast<T*>(this);
	}
};

inline std::ostream& operator<<(std::ostream& os, const Object* object) {
	if (object) return os << object->dynamicType()->name << "@" << (const void*)object;
	return os << "<nullptr>";
}

} // namespace sgd
