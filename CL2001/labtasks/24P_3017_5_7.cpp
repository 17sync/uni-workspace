#include<iostream>
using namespace std;

struct doublyNode{              
    doublyNode *prev;
    string data;
    doublyNode *next;

    doublyNode(string title): data(title), next(nullptr), prev(nullptr){}
};

class Doubly{
    doublyNode *head;
    doublyNode *tail;

    public:
    Doubly(): head(nullptr), tail(nullptr){}

    ~Doubly(){
        if(head==nullptr) return;

        doublyNode *curr=head;
        while(curr!=nullptr){
            doublyNode* temp=curr->next;
            delete curr;
            curr=temp;
        }
    }

    void pushFront(string title){
        doublyNode *newNode=new doublyNode(title);

        if(head==nullptr){
            head=tail=newNode;

            cout<<"\nAdded song successfully."<<endl;
            return;
        }

        head->prev=newNode;
        newNode->next=head;
        head=newNode;

        cout<<"\nAdded song successfully."<<endl;
    }

    void pushBack(string title){
        doublyNode *newNode=new doublyNode(title);

        if(head==nullptr){
            head=tail=newNode;

            cout<<"\nAdded song successfully."<<endl;
            return;
        }

        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;

        cout<<"\nAdded song successfully."<<endl;
    }

    void insert(string title, int index){
        if(index==0){
            pushFront(title);
            return;
        }

        doublyNode *curr=head;
        for(int i=0;i<index-1;i++){
            curr=curr->next;
            if(curr==nullptr){
                cout<<"\nPlaylist not big enough."<<endl; 
                return;
            }
        }

        if(curr==tail){
            pushBack(title);
            return;
        }

        doublyNode *newNode=new doublyNode(title);
        
        newNode->next=curr->next;
        newNode->prev=curr;
        curr->next->prev=newNode;
        curr->next=newNode;
    }

    void deleteNode(string title){
        if(head==nullptr){
            cout<<"\nPlaylist is empty."<<endl;
            return;
        }

        doublyNode *curr=head;

        if(head->data==title){
            if(head->next==nullptr){
                delete head;
                head=nullptr;
                return;
            }

            head=head->next;
            head->prev=nullptr;
            delete curr;
            cout<<"\nRemoved song successfully"<<endl;
            return;
        }

        while(curr!=nullptr){
            if(curr->data==title){
                if(curr->next!=nullptr){
                    curr->prev->next=curr->next;
                    curr->next->prev=curr->prev;
                }
                else{
                    curr->prev->next=nullptr;
                }
                delete curr;
                cout<<"\nRemoved song successfully"<<endl;
                return;
            }
            curr=curr->next;
        }

        cout<<"\nSong not Found."<<endl;
    }

    void printList(){
        doublyNode *print=head;

        cout<<"\n";
        while(print!=nullptr){
            if(print->next==nullptr) cout<<print->data;
            else cout<<print->data<<" <-> ";
            print=print->next;
        }
        cout<<endl;
    }
};

int main(){
    cout<<"24P-3017\n"<<endl;

    Doubly playlist;

    int choice;
    do{
        cout<<"\nMusic Playlist Manager\n";
        cout<<"1. Add song at end\n2. Add song at beginning\n3. Insert a song at any position\n4. Delete a song\n5. Display playlist\n6. Exit program\n";
        cout<<"Enter operation: "; cin>>choice;

        switch(choice){
            case 1:{
                string title;
                cout<<"\nEnter song title: "; cin>>title;
                playlist.pushBack(title);
                cout<<endl;
            }
            case 2:{
                string title;
                cout<<"\nEnter song title: "; cin>>title;
                playlist.pushFront(title);
                cout<<endl;
            }
            case 3:{
                string title; int pos;
                cout<<"\nEnter song title: "; cin>>title;
                cout<<"Enter position: "; cin>>pos;
                playlist.insert(title, pos);
            }
            case 4:{
                string title;
                cout<<"\nEnter song title: "; cin>>title;
                playlist.deleteNode(title);
                cout<<endl;
            }
            case 5:{
                cout<<"\nPlaylist:\n";
                playlist.printList();
            }
            case 6:{
                cout<<"\nExiting Program..."<<endl;
            }
        }
    }while(choice!=6);
}