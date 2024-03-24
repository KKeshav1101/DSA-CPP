#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct ITEM {
    float wi;
    float vi;
    float vi_by_wi;
};

struct ND {
    ND* Parent;
    int level;
    float weight_used;
    float value_gained;
    float UB;
    ND* left;
    ND* right;
};

struct CompareND {
    bool operator()(const ND* a, const ND* b) {
        return a->UB < b->UB; // Priority based on UB
    }
};

// Comparison function for sorting items based on value-to-weight ratio
bool compareItems(const ITEM& i1, const ITEM& i2) {
    return (i1.vi_by_wi > i2.vi_by_wi);
}

ND* BEST_FIRST_BB_KNAPSACK(ITEM ITEMS[], int n, float WL) {
    cout<<"here";
    ND* ROOT = new ND;
    ROOT->weight_used = 0;
    ROOT->value_gained = 0;
    ROOT->UB = WL * ITEMS[0].vi_by_wi;
    ROOT->level = 0;
    ROOT->Parent = NULL;
    ROOT->left = NULL;
    ROOT->right = NULL;
    priority_queue<ND*, vector<ND*>, CompareND> pq; // Priority queue of ND pointers
    pq.push(ROOT);

    ND* del;
    int curr_level = 0;
    while (curr_level <= n && !pq.empty()) {
        del=pq.top();
        pq.pop();
        curr_level = del->level + 1;
        ND* leftchild = new ND;
        ND* rightchild = new ND;

        leftchild->weight_used = del->weight_used + ITEMS[curr_level - 1].wi;
        if (leftchild->weight_used <= WL) {
            leftchild->value_gained = del->value_gained + ITEMS[curr_level - 1].vi;
            leftchild->Parent = del;
            leftchild->level = del->level + 1;
            if (curr_level == n)
                leftchild->UB = leftchild->value_gained;
            else
                leftchild->UB = leftchild->value_gained + (WL - leftchild->weight_used) * (ITEMS[curr_level].vi_by_wi);
            leftchild->left = NULL;
            leftchild->right = NULL;
            del->left = leftchild;
            pq.push(leftchild);
        }

        rightchild->weight_used = del->weight_used;
        rightchild->value_gained = del->value_gained;
        rightchild->Parent = del;
        rightchild->level = del->level + 1;
        if (curr_level == n)
            rightchild->UB = rightchild->value_gained;
        else
            rightchild->UB = rightchild->value_gained + (WL - rightchild->weight_used) * (ITEMS[curr_level].vi_by_wi);
        rightchild->left = NULL;
        rightchild->right = NULL;
        del->right = rightchild;
        pq.push(rightchild);
    }
    return del;
}

void RECURSIVE_PRINT(ND* NN) {
    /*static bool visited = false; // Static variable to track visited nodes
    if (NN != NULL) {
        if (NN->Parent != NULL && NN == (NN->Parent)->left && !visited) {
            cout << NN->level - 1 << ", ";
            visited = true; // Mark the node as visited
        }
        RECURSIVE_PRINT(NN->left);
        RECURSIVE_PRINT(NN->right);
        visited = false; // Reset visited status for next traversal
    }
    */
    if (NN->Parent != NULL) {
        RECURSIVE_PRINT(NN->Parent);
        if (NN == (NN->Parent)->left)
            cout << NN->level -1 << ", ";
    }
}

void BB_KNAPSACK_SOLUTION(ITEM ITEMS[], int n, float WL) {
    for (int i = 0; i < n; i++)
        ITEMS[i].vi_by_wi = ITEMS[i].vi / ITEMS[i].wi;
    sort(ITEMS, ITEMS + n, compareItems);
    ND* NN = BEST_FIRST_BB_KNAPSACK(ITEMS, n, WL);
    cout << "TOTAL PROFIT IS " << NN->UB << endl;
    cout << "ITEMS IN KNAPSACK ARE : ";
    RECURSIVE_PRINT(NN);
    cout << endl;
    delete NN;
}

int main() {
    int n;
    float WL;
    cout << "Enter problem size: ";
    cin >> n;
    ITEM ITEMS[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter w" << i << ": ";
        cin >> ITEMS[i].wi;
        cout << "Enter v" << i << ": ";
        cin >> ITEMS[i].vi;
    }
    cout << "Enter weight limit: ";
    cin >> WL;

    BB_KNAPSACK_SOLUTION(ITEMS, n, WL);

    return 0;
}