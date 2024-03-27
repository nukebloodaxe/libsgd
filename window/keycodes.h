#pragma once

// By some bizarre coincidence, these key codes are identical to those used by GLFW!

namespace sgd {

enum struct KeyCode {
	SPACE = 32,
	APOSTROPHE = 39,
	COMMA = 44,
	MINUS = 45,
	PERIOD = 46,
	SLASH = 47,
	e0 = 48,
	e1 = 49,
	e2 = 50,
	e3 = 51,
	e4 = 52,
	e5 = 53,
	e6 = 54,
	e7 = 55,
	e8 = 56,
	e9 = 57,
	SEMICOLON = 59,
	EQUAL = 61,
	A = 65,
	B = 66,
	C = 67,
	D = 68,
	E = 69,
	F = 70,
	G = 71,
	H = 72,
	I = 73,
	J = 74,
	K = 75,
	L = 76,
	M = 77,
	N = 78,
	O = 79,
	P = 80,
	Q = 81,
	R = 82,
	S = 83,
	T = 84,
	U = 85,
	V = 86,
	W = 87,
	X = 88,
	Y = 89,
	Z = 90,
	LEFT_BRACKET = 91,
	BACKSLASH = 92,
	RIGHT_BRACKET = 93,
	GRAVE_ACCENT = 96,
	WORLD_1 = 161,
	WORLD_2 = 162,

	/* Function keys */
	ESCAPE = 256,
	ENTER = 257,
	TAB = 258,
	BACKSPACE = 259,
	INSERT = 260,
	DELETE = 261,
	RIGHT = 262,
	LEFT = 263,
	DOWN = 264,
	UP = 265,
	PAGE_UP = 266,
	PAGE_DOWN = 267,
	HOME = 268,
	END = 269,
	CAPS_LOCK = 280,
	SCROLL_LOCK = 281,
	NUM_LOCK = 282,
	PRINT_SCREEN = 283,
	PAUSE = 284,
	F1 = 290,
	F2 = 291,
	F3 = 292,
	F4 = 293,
	F5 = 294,
	F6 = 295,
	F7 = 296,
	F8 = 297,
	F9 = 298,
	F10 = 299,
	F11 = 300,
	F12 = 301,
	F13 = 302,
	F14 = 303,
	F15 = 304,
	F16 = 305,
	F17 = 306,
	F18 = 307,
	F19 = 308,
	F20 = 309,
	F21 = 310,
	F22 = 311,
	F23 = 312,
	F24 = 313,
	F25 = 314,
	KP_0 = 320,
	KP_1 = 321,
	KP_2 = 322,
	KP_3 = 323,
	KP_4 = 324,
	KP_5 = 325,
	KP_6 = 326,
	KP_7 = 327,
	KP_8 = 328,
	KP_9 = 329,
	KP_DECIMAL = 330,
	KP_DIVIDE = 331,
	KP_MULTIPLY = 332,
	KP_SUBTRACT = 333,
	KP_ADD = 334,
	KP_ENTER = 335,
	KP_EQUAL = 336,
	LEFT_SHIFT = 340,
	LEFT_CONTROL = 341,
	LEFT_ALT = 342,
	LEFT_SUPER = 343,
	RIGHT_SHIFT = 344,
	RIGHT_CONTROL = 345,
	RIGHT_ALT = 346,
	RIGHT_SUPER = 347,
	MENU = 348,
	LAST = MENU,
};

enum struct KeyModMask {
	SHIFT = 0x0001,
	CONTROL = 0x0002,
	ALT = 0x0004,
	SUPER = 0x0008,
	CAPS_LOCK = 0x0010,
	NUM_LOCK = 0x0020
};

#if 0
using KeyCode = uint32_t;
using KeyMask = uint32_t;

constexpr KeyCode SGD_KEY_SPACE = 32;
constexpr KeyCode SGD_KEY_APOSTROPHE = 39;
constexpr KeyCode SGD_KEY_COMMA = 44;
constexpr KeyCode SGD_KEY_MINUS = 45;
constexpr KeyCode SGD_KEY_PERIOD = 46;
constexpr KeyCode SGD_KEY_SLASH = 47;
constexpr KeyCode SGD_KEY_0 = 48;
constexpr KeyCode SGD_KEY_1 = 49;
constexpr KeyCode SGD_KEY_2 = 50;
constexpr KeyCode SGD_KEY_3 = 51;
constexpr KeyCode SGD_KEY_4 = 52;
constexpr KeyCode SGD_KEY_5 = 53;
constexpr KeyCode SGD_KEY_6 = 54;
constexpr KeyCode SGD_KEY_7 = 55;
constexpr KeyCode SGD_KEY_8 = 56;
constexpr KeyCode SGD_KEY_9 = 57;
constexpr KeyCode SGD_KEY_SEMICOLON = 59;
constexpr KeyCode SGD_KEY_EQUAL = 61;
constexpr KeyCode SGD_KEY_A = 65;
constexpr KeyCode SGD_KEY_B = 66;
constexpr KeyCode SGD_KEY_C = 67;
constexpr KeyCode SGD_KEY_D = 68;
constexpr KeyCode SGD_KEY_E = 69;
constexpr KeyCode SGD_KEY_F = 70;
constexpr KeyCode SGD_KEY_G = 71;
constexpr KeyCode SGD_KEY_H = 72;
constexpr KeyCode SGD_KEY_I = 73;
constexpr KeyCode SGD_KEY_J = 74;
constexpr KeyCode SGD_KEY_K = 75;
constexpr KeyCode SGD_KEY_L = 76;
constexpr KeyCode SGD_KEY_M = 77;
constexpr KeyCode SGD_KEY_N = 78;
constexpr KeyCode SGD_KEY_O = 79;
constexpr KeyCode SGD_KEY_P = 80;
constexpr KeyCode SGD_KEY_Q = 81;
constexpr KeyCode SGD_KEY_R = 82;
constexpr KeyCode SGD_KEY_S = 83;
constexpr KeyCode SGD_KEY_T = 84;
constexpr KeyCode SGD_KEY_U = 85;
constexpr KeyCode SGD_KEY_V = 86;
constexpr KeyCode SGD_KEY_W = 87;
constexpr KeyCode SGD_KEY_X = 88;
constexpr KeyCode SGD_KEY_Y = 89;
constexpr KeyCode SGD_KEY_Z = 90;
constexpr KeyCode SGD_KEY_LEFT_BRACKET = 91;
constexpr KeyCode SGD_KEY_BACKSLASH = 92;
constexpr KeyCode SGD_KEY_RIGHT_BRACKET = 93;
constexpr KeyCode SGD_KEY_GRAVE_ACCENT = 96;
constexpr KeyCode SGD_KEY_WORLD_1 = 161;
constexpr KeyCode SGD_KEY_WORLD_2 = 162;

/* Function keys */
constexpr KeyCode SGD_KEY_ESCAPE = 256;
constexpr KeyCode SGD_KEY_ENTER = 257;
constexpr KeyCode SGD_KEY_TAB = 258;
constexpr KeyCode SGD_KEY_BACKSPACE = 259;
constexpr KeyCode SGD_KEY_INSERT = 260;
constexpr KeyCode SGD_KEY_DELETE = 261;
constexpr KeyCode SGD_KEY_RIGHT = 262;
constexpr KeyCode SGD_KEY_LEFT = 263;
constexpr KeyCode SGD_KEY_DOWN = 264;
constexpr KeyCode SGD_KEY_UP = 265;
constexpr KeyCode SGD_KEY_PAGE_UP = 266;
constexpr KeyCode SGD_KEY_PAGE_DOWN = 267;
constexpr KeyCode SGD_KEY_HOME = 268;
constexpr KeyCode SGD_KEY_END = 269;
constexpr KeyCode SGD_KEY_CAPS_LOCK = 280;
constexpr KeyCode SGD_KEY_SCROLL_LOCK = 281;
constexpr KeyCode SGD_KEY_NUM_LOCK = 282;
constexpr KeyCode SGD_KEY_PRINT_SCREEN = 283;
constexpr KeyCode SGD_KEY_PAUSE = 284;
constexpr KeyCode SGD_KEY_F1 = 290;
constexpr KeyCode SGD_KEY_F2 = 291;
constexpr KeyCode SGD_KEY_F3 = 292;
constexpr KeyCode SGD_KEY_F4 = 293;
constexpr KeyCode SGD_KEY_F5 = 294;
constexpr KeyCode SGD_KEY_F6 = 295;
constexpr KeyCode SGD_KEY_F7 = 296;
constexpr KeyCode SGD_KEY_F8 = 297;
constexpr KeyCode SGD_KEY_F9 = 298;
constexpr KeyCode SGD_KEY_F10 = 299;
constexpr KeyCode SGD_KEY_F11 = 300;
constexpr KeyCode SGD_KEY_F12 = 301;
constexpr KeyCode SGD_KEY_F13 = 302;
constexpr KeyCode SGD_KEY_F14 = 303;
constexpr KeyCode SGD_KEY_F15 = 304;
constexpr KeyCode SGD_KEY_F16 = 305;
constexpr KeyCode SGD_KEY_F17 = 306;
constexpr KeyCode SGD_KEY_F18 = 307;
constexpr KeyCode SGD_KEY_F19 = 308;
constexpr KeyCode SGD_KEY_F20 = 309;
constexpr KeyCode SGD_KEY_F21 = 310;
constexpr KeyCode SGD_KEY_F22 = 311;
constexpr KeyCode SGD_KEY_F23 = 312;
constexpr KeyCode SGD_KEY_F24 = 313;
constexpr KeyCode SGD_KEY_F25 = 314;
constexpr KeyCode SGD_KEY_KP_0 = 320;
constexpr KeyCode SGD_KEY_KP_1 = 321;
constexpr KeyCode SGD_KEY_KP_2 = 322;
constexpr KeyCode SGD_KEY_KP_3 = 323;
constexpr KeyCode SGD_KEY_KP_4 = 324;
constexpr KeyCode SGD_KEY_KP_5 = 325;
constexpr KeyCode SGD_KEY_KP_6 = 326;
constexpr KeyCode SGD_KEY_KP_7 = 327;
constexpr KeyCode SGD_KEY_KP_8 = 328;
constexpr KeyCode SGD_KEY_KP_9 = 329;
constexpr KeyCode SGD_KEY_KP_DECIMAL = 330;
constexpr KeyCode SGD_KEY_KP_DIVIDE = 331;
constexpr KeyCode SGD_KEY_KP_MULTIPLY = 332;
constexpr KeyCode SGD_KEY_KP_SUBTRACT = 333;
constexpr KeyCode SGD_KEY_KP_ADD = 334;
constexpr KeyCode SGD_KEY_KP_ENTER = 335;
constexpr KeyCode SGD_KEY_KP_EQUAL = 336;
constexpr KeyCode SGD_KEY_LEFT_SHIFT = 340;
constexpr KeyCode SGD_KEY_LEFT_CONTROL = 341;
constexpr KeyCode SGD_KEY_LEFT_ALT = 342;
constexpr KeyCode SGD_KEY_LEFT_SUPER = 343;
constexpr KeyCode SGD_KEY_RIGHT_SHIFT = 344;
constexpr KeyCode SGD_KEY_RIGHT_CONTROL = 345;
constexpr KeyCode SGD_KEY_RIGHT_ALT = 346;
constexpr KeyCode SGD_KEY_RIGHT_SUPER = 347;
constexpr KeyCode SGD_KEY_MENU = 348;
constexpr KeyCode SGD_KEY_LAST = SGD_KEY_MENU;

constexpr KeyMask SGF_MOD_SHIFT = 0x0001;
constexpr KeyMask SGF_MOD_CONTROL = 0x0002;
constexpr KeyMask SGF_MOD_ALT = 0x0004;
constexpr KeyMask SGF_MOD_SUPER = 0x0008;
constexpr KeyMask SGF_MOD_CAPS_LOCK = 0x0010;
constexpr KeyMask SGF_MOD_NUM_LOCK = 0x0020;
#endif

} // namespace sgd
