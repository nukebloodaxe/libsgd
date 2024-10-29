#pragma once

#include "material.h"

namespace sgd {

Material* createMaterial(CString type);
Expected<Material*, FileioEx> loadMaterial(CPath path);

Material* createPBRMaterial();
Expected<Material*, FileioEx> loadPBRMaterial(CPath path);

Material* createPrelitMaterial();
Expected<Material*, FileioEx> loadPrelitMaterial(CPath path);

Material* createEmissiveMaterial();
Expected<Material*, FileioEx> loadEmissiveMaterial(CPath path);

}
