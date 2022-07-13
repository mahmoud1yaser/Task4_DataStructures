#include "my_tree.h"
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{

    int SizeOfTree;
    int OperationsNumber;
    int Element;
    vector<int> v;
    cin >> SizeOfTree >> OperationsNumber;
    for (int i = 0; i < SizeOfTree; i++)
    {
        cin >> Element;
        v.push_back(Element);
    }
    MyTree <int> tree(v);
    for (int i = 0; i < OperationsNumber; i++)
    {
        int x;
        cin >> x;
        switch (x) {
            case 1:
                cin >> Element;
                tree.Insert(Element);
                break;
            case 2: {
                cin >> Element;
                bool ss = tree.Search(Element);
                if (ss)
                    cout<<1<<" "<<endl;
                else
                    cout<<0<<" "<<endl;
                break;
            }
            case 3:
                cin >> Element;
                if (Element == 1){
                    tree.InorderRec();
                    cout << endl;
                }
                if (Element == 2){
                    tree.Inorder();
                    cout << endl;
                }
                break;
            case 4:
                cin>>Element;
                if ( Element==1){
                    tree.PreorderRec();
                    cout << endl;
                }
                if (Element==2){
                    tree.Preorder();
                    cout << endl;
                }
                break;
            case 5:
                cin>>Element;
                if (Element == 1)
                    tree.PostorderRec();
                else tree.Postorder();

                break;
            case 6:
                tree.BreadthTraversal();
                cout<<endl;
                break;
            case 7:
                cout<<tree.Size();
                cout<<" "<<endl;
                break;
        }


    }
}