#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ff first
#define ss second
#define nline "\n"
#define ll long long
#define all(ar) ar.begin(), ar.end()
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define debug(args...){string _s=#args;replace(_s.begin(),_s.end(),',',' ');stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it,args);}
void err(istream_iterator<string> it) {}
template<typename T,typename... Args> void err(istream_iterator<string> it,T a,Args... args){cerr<<*it<<" = "<<a<<"\n";err(++it,args...);}
template<typename T> void _print(T _t){cout<<"[ ";for(auto _x:_t){cout<<_x<<" ";}cout<<" ]\n";}
template<class T> void _print(map<T, T> x){for(auto i:x)cout<<i.ff<<" "<<i.ss<<"\n";}
/*---------------------------Codes-----------------------------*/

class Trie {
    Trie* children[26];
    bool endMark;

public:
    Trie() {
        endMark = false;
        for (int i = 0; i < 26; ++i) 
            children[i] = nullptr;
    }

    void Insert(string s) {
        Trie* t = this;
        for (int i = s.size()-1; i >= 0; --i) {
            int idx = s[i] - 'a';
            if (t->children[idx] == nullptr)
                t->children[idx] = new Trie();
            
            t = t->children[idx];
        }
        t->endMark = true;
    }

    bool Search(deque<char>& s) {
        Trie* t = this;
        for (int i = 0, len = s.size(); i < len; ++i) {
            int idx = s[i] - 'a';
            if (t->children[idx] == nullptr) return false;
            t = t->children[idx];
            if (t->endMark) return true;
        }
        return false;
    }
};

class StreamChecker {
    Trie t;
    deque<char> stream;
public:
    StreamChecker(vector<string>& words) {
        for (string w : words) {
            //reverse(all(w));
            t.Insert(w);
        }
    }
    
    bool query(char letter) {
        stream.push_front(letter);
        return t.Search(stream);
    }
};


int main() {
    FASTIO;
#ifdef DEBUG_LOCAL
    FI;
#endif
    
    vector<string> words = { "cd", "f", "kl" };

    StreamChecker* streamChecker = new StreamChecker(words);
    cout << streamChecker->query('a') << nline; // return False
    cout << streamChecker->query('b') << nline; // return False
    cout << streamChecker->query('c') << nline; // return False
    cout << streamChecker->query('d') << nline; // return True, because 'cd' is in the wordlist
    cout << streamChecker->query('e') << nline; // return False
    cout << streamChecker->query('f') << nline; // return True, because 'f' is in the wordlist
    cout << streamChecker->query('g') << nline; // return False
    cout << streamChecker->query('h') << nline; // return False
    cout << streamChecker->query('i') << nline; // return False
    cout << streamChecker->query('j') << nline; // return False
    cout << streamChecker->query('k') << nline; // return False
    cout << streamChecker->query('l') << nline; // return True, because 'kl' is in the wordlist
    
    return 0;
}
