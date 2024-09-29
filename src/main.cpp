#define TINYGLTF_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define TINYGLTF_ENABLE_DRACO

#include "tiny_gltf.h"
#include <iostream>

using namespace tinygltf;

void PrintAttributeValues(const Model& model) {
    for (size_t i = 0; i < model.meshes.size(); ++i) {
        const Mesh& mesh = model.meshes[i];
        std::cout << "Mesh " << i << " (" << mesh.name << "):" << std::endl;

        for (size_t j = 0; j < mesh.primitives.size(); ++j) {
            const Primitive& primitive = mesh.primitives[j];
            std::cout << "  Primitive " << j << ":" << std::endl;

            // Print the attributes for this primitive
            for (const auto& attribute : primitive.attributes) {
                const std::string& attributeName = attribute.first;
                int accessorIndex = attribute.second;
                const Accessor& accessor = model.accessors[accessorIndex];
                const BufferView& bufferView = model.bufferViews[accessor.bufferView];
                const Buffer& buffer = model.buffers[bufferView.buffer];

                std::cout << "    Attribute: " << attributeName << std::endl;
                std::cout << "      Type: " << accessor.type << std::endl;
                std::cout << "      Component Type: " << accessor.componentType << std::endl;
                std::cout << "      Count: " << accessor.count << std::endl;

                // Calculate the pointer to the attribute data
                const unsigned char* dataPtr = &buffer.data[accessor.byteOffset + bufferView.byteOffset];

                // Example for POSITION (assuming it's stored as float)
                if (accessor.componentType == TINYGLTF_COMPONENT_TYPE_FLOAT) {
                    const float* floatData = reinterpret_cast<const float*>(dataPtr);

                    // Print out the values for POSITION or TEXCOORD_0
                    for (size_t k = 0; k < accessor.count; ++k) {
                        std::cout << "        Value [" << k << "]: (";
                        for (size_t l = 0; l < accessor.type; ++l) {
                            std::cout << floatData[k * accessor.type + l];
                            if (l < accessor.type - 1) {
                                std::cout << ", ";
                            }
                        }
                        std::cout << ")" << std::endl;
                    }
                }
            }
        }
    }
}

int main() {
    Model model;
    TinyGLTF loader;
    std::string err;
    std::string warn;

    std::string filename = "../../3d-model/UlRPVEYubm9kZWRhdGEucGxhbmV0b2lkPWVhcnRoLG5vZGVfZGF0YV9lcG9jaD05MzgscGF0aD0yMTQyNzM2MTQxNTM2Mzc1MzExMyxjYWNoZV92ZXJzaW9uPTY.glb";

    bool ret = loader.LoadBinaryFromFile(&model, &err, &warn, filename);

    if (!warn.empty()) {
        std::cout << "Warning: " << warn << std::endl;
    }

    if (!err.empty()) {
        std::cerr << "Error: " << err << std::endl;
    }

    if (!ret) {
        std::cerr << "Failed to load .glb model: " << filename << std::endl;
        return 0;
    }

    // Print attributes of the loaded model
    PrintAttributeValues(model);

    return 0;
}
