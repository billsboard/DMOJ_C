#include <iostream>
#include <string>
#include <map>

using namespace std;

string zod[] = {
    "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat",
    "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat",
    "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat",
    "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"
};

int N;
string s, t, u, v;
map<string, int> mp, z;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    z["Ox"] = 0;
    z["Tiger"] = 1;
    z["Rabbit"] = 2;
    z["Dragon"] = 3;
    z["Snake"] = 4;
    z["Horse"] = 5;
    z["Goat"] = 6;
    z["Monkey"] = 7;
    z["Rooster"] = 8;
    z["Dog"] = 9;
    z["Pig"] = 10;
    z["Rat"] = 11;

    mp["Bessie"] = 0;
    cin >> N;


    while (N--)
    {
        cin >> s;
        cin >> t >> t >> t;
        cin >> u;
        cin >> v >> v >> v;

        //cout << s << t << u << v << "\n";

        if(t == "previous"){
            int beg = (mp[v] % 12 + 12) % 12;
            int idx = beg + 12 - 1, dec = 1;
            while (zod[idx] != u)
            {
                idx--;
                dec++;
            }

            mp[s] = mp[v] - dec;
        }
        else if(t == "next"){
            int beg = (mp[v] % 12 + 12) % 12;
            int idx = beg + 12 + 1, inc = 1;
            while (zod[idx] != u)
            {
                idx++;
                inc++;
            }

            mp[s] = mp[v] + inc;
        }
    }

    cout << abs(mp["Elsie"]) << "\n";
}