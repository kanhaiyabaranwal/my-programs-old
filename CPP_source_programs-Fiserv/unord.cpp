#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
using namespace std::tr1;

int main()
{
    unordered_map<string, size_t> umap1, umap2;
    umap1["Key"] = 1;
    umap2 = umap1;

    cout << "Dump before erase:" << endl;
    cout << "umap1: " << endl; umap1._Dump();
    cout << "umap2: " << endl; umap2._Dump();

    umap2.erase("Key");

    cout << "Dump after erase:" << endl;
    cout << "umap1: " << endl; umap1._Dump();
    cout << "umap2: " << endl; umap2._Dump();

    cout << "Iteration after erase:" << endl;
    cout << "umap1: " << endl;

    for(unordered_map<string, size_t>::iterator iter =
umap1.begin();
        iter != umap1.end();
        ++iter) {
        const unordered_map<string, size_t>::value_type vt =
*iter;
        cout << "key="     << vt.first.c_str()
             << ", value=" << vt.second
             << endl;
    }

    cout << "umap2: " << endl;

    for(unordered_map<string, size_t>::iterator iter =
umap2.begin();
        iter != umap2.end();
        ++iter) {
        const unordered_map<string, size_t>::value_type vt =
*iter;
        cout << "key="     << vt.first.c_str()
             << ", value=" << vt.second
             << endl;
    }
	return 0;
}

