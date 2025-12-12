#include "../Management/ObjLoader.h"
#include <fstream>
OBJ::OBJ(const string& path) {
    ifstream MyReadFile(path);
    string line;
    vector<vector<int>> faces;

    while (getline(file, line)) {  // read the content from the .obj file that has the vertices and the indices, and go line by line
        stringstream ss(line);  // Go char by char, which in this case, is vertices by vertices, or edges by edges
        string type;
        ss >> type;  // Read the specifi char into type each time it loops through, i.e., vertex and edge
 
        if(type == "v") {
            float m, n, p;

            ss >> m >> n >> p;
            vertices.push_back({m, n, p});
        }

        if(type == "f") {
            vector<int> face;
            int index;

            while (ss >> index) {
                face.push_back(index-1);
            }
            faces.push_back(face);
        }

        for (auto& f:faces) {
            for (int i = 0; i < f.size(); i++) {
                int a = f[i];
                int b = f[(i+1) % f.size()];

                edges.push_back({a,b});
            }
        }

    }
}
