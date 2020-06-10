// 输入："/a/../../b/../c//.//"
// 输出："/c"

class Solution {
public:
    string simplifyPath(string path) {
        stack<char> con;
        string result;
        for(int i=0; i<path.size(); i++){
            if(path[i]=='/'){
                if(i+1 == path.size() || (i+1 < path.size() && path[i+1] == '/') || (!con.empty() && con.top()=='/')) continue;
                else con.push(path[i]);
            }else if(path[i] == '.'){
                if(i+2 <path.size() && path[i] == '.' && path[i+1] == '.' && path[i+2] != '/'){
                    con.push('.');con.push('.');con.push(path[i+2]);
                    i+=2;
                }
                else if(i+1 < path.size() && path[i+1] == '.'){
                    i++;
                    if(!con.empty() && con.top() == '/'){
                        con.pop();
                        while(!con.empty()){
                            char cur = con.top(); con.pop();
                            if(cur == '/') break;
                        }
                        if(con.empty()) con.push('/');
                    }
                }else if(i+1 < path.size() && path[i+1] != '/') con.push(path[i]);
            }else con.push(path[i]);
        }
        if(con.empty()) con.push('/');
        while(!con.empty() && con.size() != 1 &&con.top() == '/'){
            con.pop();
        }
        while(!con.empty()){
            result += con.top(); con.pop();
        }
        reverse(result.begin(), result.end());
        return result; 
    }
};


////////////////////

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        istringstream iss(path);
        string buf;
        while (getline(iss, buf, '/')) {
            if (!buf.empty() && buf != "." && buf != "..") {
                v.push_back(buf);
            } else if (!v.empty() && buf == "..") {
                v.pop_back();
            }
        }
        if (v.empty()) {
            return "/";
        }

        buf.clear();
        for (string &s : v) {
            buf += "/";
            buf += s;
        }
        return buf;
    }
};