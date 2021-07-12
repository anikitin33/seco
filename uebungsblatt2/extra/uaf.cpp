#include <chrono>
#include <ctime>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct auth {
    int level;
    char user[12];
};

const int NA = 10;
vector<auth *> authorizations(NA, 0);
int anextfree = 0;
vector<char *> services;

void useservice(auth* a, const string& service) {
    if (a == nullptr) {
        cout << "USE must select a user for authorization first " << endl;
        return;
    }
    if (service == string("secret")) {
        if (a->level < 17) {
            cout << "auth level too low, sorry" << endl;
            return;
        }
        cout << "real secret only available on x2go.vswt.swt.hs-mannheim.de";
        cout << endl;
        return;
    } else if (service == string("hi")) {
        cout << "Hi " << a->user << endl;
        return;
    } else if (service == string("time")) {
        auto now = std::chrono::system_clock::now();
        time_t tnow = std::chrono::system_clock::to_time_t(now);
        cout << ctime(&tnow);
        return;
    } else {
        for (auto s : services) {
            if (s == service) {
                cout << "using custom service " << service << endl;
                return;
            }
        } 
        cout << "I do not know the service " << service << endl;
    }
}

void addservice(const string& service, bool verbose=true) {
    // services.push_back(strdup(service.c_str()));
    char* s = new char[strlen(service.c_str()) + 1];
    strcpy(s, service.c_str());
    services.push_back(s);
    if (verbose) {
        cout << "FEATURE " << service << endl;
    }
}

void addauth(const string& user, int level=0) {
    if (anextfree == NA) {
        cout << "no more space to add" << endl;
        return;
    }
    auth* fresh = new auth {level, 0};
    strncpy(fresh->user, user.c_str(), 12);
    fresh->user[11] = 0;
    if (level == 0) {
        cout << "ADD user=" << user << " at position " << anextfree << endl;
    }
    authorizations[anextfree++] = fresh;
}

auth* selectauth(const string& user) {
    auth* selected = nullptr;
    auto it = authorizations.begin();
    ++it; // not admin                           
    while (it != authorizations.end()) {
        auth* a = *it++;
        if (a != nullptr && user == string(a->user)) {
            selected = a;
            break;
        }
    }
    if (selected == nullptr) {
        cout << "SELECT did not find anything" << endl;
    } else {
        cout << "SELECTED " << selected->user << endl;
    }
    return selected;
}

void removeauth(const string& user) {
    auto it = authorizations.begin();
    ++it; // not admin
    int i=1;
    while (it != authorizations.end()) {
        auth* a = *it++;
        if (a != nullptr && user == string(a->user)) {
            delete a;
            a = nullptr;
            cout << "removed " << user << " at position " << i << endl;
        }
        ++i;
    }
}

void init() {
    addauth(string("admin"), 42);
    string servicenames[] = { "secret", "hi", "time" };
    for (string sn : servicenames) {
        addservice(sn, false);
    }
}

void cleanup() {
    for (auto cptr : services) {
        // free(cptr);
        delete[] cptr;
    }
}

int main() {
    init();
    string cmd;
    auth* selected = nullptr;
    do {
        cin >> cmd;
        if (cmd == "" || cmd[0] == '#') { // empty or comment
            std::getline (std::cin, cmd); // forget line
            continue;
        }
        if (cmd == "quit" || !cin) { break; }
        if (cmd == "add") {
            string user; cin >> user;
            addauth(user);
        } else if (cmd == "select") {
            string user; cin >> user;
            selected = selectauth(user);
        } else if (cmd == "remove") {
            string user; cin >> user;
            removeauth(user);            
        } else if (cmd == "use") {
            string service; cin >> service;
            useservice(selected, service);
        } else if (cmd == "feature") {
            string service; cin >> service;
            addservice(service);
        } else {
            cout << "I do not understand " << cmd << endl;
        }
    } while (true);
    cleanup();
}
