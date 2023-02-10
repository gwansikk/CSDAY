#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<string, int> map;
    string fileName, extName;
    int n, pos; 

    cin >> n;
    while (n--) {
        cin >> fileName;
        pos = fileName.find('.');
        extName = fileName.substr(pos + 1);
        if (map.find(extName) != map.end())
            map[extName]++;
        else
            map.insert({extName, 1});
    }
    
    for (auto iter : map)
        cout << iter.first << " " << iter.second << "\n";

    return 0;
}