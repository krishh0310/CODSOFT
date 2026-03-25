#include <iostream>
#include <vector>
using namespace std;

struct Task {
    string name;
    bool done = false;
};

vector<Task> tasks;

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks.\n";
        return;
    }
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].name
             << " [" << (tasks[i].done ? "Done" : "Pending") << "]\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n1.Add  2.View  3.Complete  4.Delete  5.Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            cin.ignore();
            string t;
            cout << "Task: ";
            getline(cin, t);
            tasks.push_back({t, false});
        }
        else if (choice == 2) {
            viewTasks();
        }
        else if (choice == 3) {
            int n;
            viewTasks();
            cout << "Task no: ";
            cin >> n;
            if (n >= 1 && n <= tasks.size())
                tasks[n - 1].done = true;
        }
        else if (choice == 4) {
            int n;
            viewTasks();
            cout << "Task no: ";
            cin >> n;
            if (n >= 1 && n <= tasks.size())
                tasks.erase(tasks.begin() + n - 1);
        }

    } while (choice != 5);

    return 0;
}
