//Job matching code for Rabin karp
#include <iostream>
#include <string>
using namespace std;

const int PRIME = 101;

long long calculateHash(const string &str, int length) {
    long long hash = 0;
    for (int i = 0; i < length; i++) {
        hash = (hash * 256 + str[i]) % PRIME;
    }
    return hash;
}

bool rabinKarp(const string &text, const string &pattern) {
    int n = text.size();
    int m = pattern.size();

    if (m > n) return false;

    long long patternHash = calculateHash(pattern, m);
    long long textHash = calculateHash(text, m);

    long long highestPower = 1;
    for (int i = 0; i < m - 1; i++) {
        highestPower = (highestPower * 256) % PRIME;
    }

    for (int i = 0; i <= n - m; i++) {
        if (patternHash == textHash && text.substr(i, m) == pattern) {
            return true;
        }

        if (i < n - m) {
            textHash = (256 * (textHash - text[i] * highestPower) + text[i + m]) % PRIME;
            if (textHash < 0) textHash += PRIME;
        }
    }

    return false;
}

bool matchSkills(const string &jobRequirement, const string &candidateSkills) {
    // Split jobRequirement into individual skills and check each one
    size_t start = 0, end;
    while ((end = jobRequirement.find(' ', start)) != string::npos) {
        string requiredSkill = jobRequirement.substr(start, end - start);
        if (!rabinKarp(candidateSkills, requiredSkill)) {
            return false; // If any required skill is missing, return false
        }
        start = end + 1;
    }

    // Check the last skill in the requirement list
    string lastSkill = jobRequirement.substr(start);
    return rabinKarp(candidateSkills, lastSkill);
}

int main() {
    string jobRequirement = "C++ Java SQL";
    cout << "Job available for candidates with skills: " << jobRequirement << endl;

    while (true) {
        string skills;
        cout << "Please apply for the job by entering your skills (or type 'exit' to stop): ";
        getline(cin, skills);

        if (skills == "exit") {
            cout << "Thank you for applying!" << endl;
            break;
        }

        if (matchSkills(jobRequirement, skills)) {
            cout << "Congratulations! Your skills match the job requirement." << endl;
        } else {
            cout << "Sorry, your skills do not match the job requirement." << endl;
        }
    }

    return 0;
}


 
    

//Code for job distribution optimisation using kruskal algorithm
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to check and assign job location
void assignJobs(const vector<string>& employeeAddresses, const string& industryAddress) {
    cout << "\nJob Assignment Results:\n";
    for (int i = 0; i < employeeAddresses.size(); i++) {
        if (employeeAddresses[i] == industryAddress) {
            cout << "Employee " << i + 1 << ": Job Location Assigned (Address: " << employeeAddresses[i] << ")\n";
        } else {
            cout << "Employee " << i + 1 << ": No Job Location Assigned (Address: " << employeeAddresses[i] << ")\n";
        }
    }
}

int main() {
    int numEmployees;
    string industryAddress;

    // Input the industry address
    cout << "Enter the industry address: ";
    getline(cin, industryAddress);

    // Input the number of employees
    cout << "Enter the number of employees: ";
    cin >> numEmployees;
    cin.ignore(); // To consume the newline character after the number input

    // Input employee addresses
    vector<string> employeeAddresses(numEmployees);
    cout << "Enter the addresses of employees:\n";
    for (int i = 0; i < numEmployees; i++) {
        cout << "Address of Employee " << i + 1 << ": ";
        getline(cin, employeeAddresses[i]);
    }

    // Assign jobs based on address matching
    assignJobs(employeeAddresses, industryAddress);

    return 0;
}

//Code for job distribution optimisation using prime algorithm
#include <iostream>
#include <string>
using namespace std;

// Function to check if two addresses are the same
bool isSameAddress(const string &employeeAddress, const string &industryAddress) {
    return employeeAddress == industryAddress;
}

int main() {
    string employeeAddress, industryAddress;
    string jobLocation;

    // Taking inputs from the user
    cout << "Enter the address of the employee: ";
    getline(cin, employeeAddress);
    cout << "Enter the address of the industry: ";
    getline(cin, industryAddress);

    // Check if the addresses match
    if (isSameAddress(employeeAddress, industryAddress)) {
        jobLocation = industryAddress;
        cout << "Job location assigned: " << jobLocation << endl;
    } else {
        cout << "Addresses do not match. No job location assigned." << endl;
    }

    return 0;
}

//Code for job distribution optimisation using floyds algorithm
Here is the C++ code for Job Distribution Optimization using Floyd's Algorithm:

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define INF INT_MAX

void floydWarshall(vector<vector<int>>& graph, int n) {
    vector<vector<int>> dist = graph;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "Optimized Job Distribution Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of locations: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the adjacency matrix (use " << INF << " for no direct route):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    floydWarshall(graph, n);

    return 0;
}


