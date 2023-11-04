#include <iostream>
#include <vector>
using namespace std;

class SET{
    public:
        vector <int> elements;
        int length=0;
    bool BelongsTo(int data){
        for (int i=0; i<length; i++){
            if (elements[i]==data){
                return true;
            }
        }
        return false;
    }
    void Insert(int data){
         if (BelongsTo(data)== true) {
        //nothing to do
    } 
    else {
        int index = 0;
        while (index < elements.size() && data > elements[index]) {
            index++;
        }
        SET temp;
        for (int j = 0; j < index; j++) {
            temp.elements.push_back(elements[j]);
        }
        temp.elements.push_back(data);
        for (int j = index; j < elements.size(); j++) {
            temp.elements.push_back(elements[j]);
        }
        elements = temp.elements;
        length++;
    }
    }
    void Delete(int data){
        for(int i=0;i<elements.size();i++){
            if(elements[i]==data){
                elements.erase(elements.begin()+i);
                length--;
            }
        }
    }
    void Union(SET set_2){
         for(int i=0;i<set_2.elements.size();i++){
            if(BelongsTo(set_2.elements[i])==false){
                Insert(set_2.elements[i]);
            }
            else{
                continue;
            }
         }
     }
    void Intersection( SET set_2) {
    SET temp;
        for (int i = 0; i < length; i++) {
            if (set_2.BelongsTo(elements[i])==true) { 
                temp.Insert(elements[i]); 
            }
        }
    elements = temp.elements; 
    length = temp.length;
    cout << length << endl;
}
        
    void Size(){
        cout<<length<<endl;
    }
    void Print(){
        for (int i=0; i <length-1; i++){
            cout<<elements[i]<<",";
        }
        cout<<elements[length-1]<<endl;
    }
     void Difference(SET set2){
        for(int i=0;i<set2.length;i++){
            if(BelongsTo(set2.elements[i])==true){
                Delete(set2.elements[i]);
            }
            else{
                continue;
            }
        }
        cout<<length<<endl;
    }
    void SymmetricDifference(SET set_2){
        for (int i=0; i<set_2.length; i++){
            if (BelongsTo(set_2.elements[i])==true){
                Delete(set_2.elements[i]);
            }
            else{
                Insert(set_2.elements[i]);
            }
        }
        cout<<length<<endl;
    }
};
int main() {
    vector<SET> sets;
    int command;
    int num;
    int data;
    
    while(cin>>command){
        if(command==1){
            cin>>num;
            cin>>data;
             if (num<sets.size()){
                sets[num].Insert(data);
            }
            else{
                SET k;
                sets.push_back(k);
                sets[num].Insert(data);
            }
            sets[num].Size();
            continue;
        }
        else if(command==2){
            cin>>num;
            cin>>data;
            if(num<sets.size()){
                sets[num].Delete(data);
            }
            else{
            cout<<-1<<endl;
            }
            sets[num].Size();
        }
        else if(command==3){
            cin>>num;
            cin>>data;
            if(num<sets.size()){
                if(sets[num].BelongsTo(data)==true){
                    cout<<1<<endl;
                }
                else{
                    cout<<0<<endl;
                }
            }
            else if(num>=sets.size()){
                cout<<-1<<endl;
            }
        }
        else if(command==4){
            cin>>num;
            cin>>data;
            if(num<sets.size()){
              sets[num].Union(sets[data]);
              
            }
            else if (num>=sets.size() || data>=sets.size()){
            SET d;
            sets.push_back(d);
            sets[num].Union(sets[data]);
            
            }
            cout<<sets[num].length<<endl;
        }
        else if (command==5){
		    cin>>num;
        	cin>>data;
            if (num<sets.size() && data<sets.size()){
                sets[num].Intersection(sets[data]);
            }
            else if (num>=sets.size() || data>=sets.size()){
                SET t;
                sets.push_back(t);
                sets[num].Intersection(sets[data]);
            }
        
    }
        else if(command==6){
            cin>>num;
              if (num<sets.size()){
                sets[num].Size();
              }
              else{
                  cout<<0<<endl;
              }
        }
        else if(command==7){
            cin>>num;
            cin>>data;
             if (num<sets.size() || data<sets.size()){
                 sets[num].Difference(sets[data]);
                 
             }
             else if(data<sets.size() && num>=sets.size()){
                 SET r;
                 sets.push_back(r);
                 cout<<0<<endl;
             }
             else if(data>=sets.size() && num<sets.size()){
                 SET r;
                 sets.push_back(r);
                 cout<<sets[num].length<<endl;  
             }
             else{
                 SET r;
                 SET e;
                 sets.push_back(r);
                 sets.push_back(e);
                 cout<<0<<endl;
             }
        }
        else if(command==8){
            cin>>num;
            cin>>data;
              if (num<sets.size() || data<sets.size()){
                  sets[num].SymmetricDifference(sets[data]);
              }
              else if(data<sets.size() && num>=sets.size()){
                  SET r;
                  sets.push_back(r);
                  cout<<sets[num].length<<endl;
              }
              else if(data>=sets.size() && num<sets.size()){
                  SET r;
                  sets.push_back(r);
                  cout<<sets[data].length<<endl;  
              }
              else{
                  SET r;
                  SET e;
                  sets.push_back(r);
                  sets.push_back(e);
                  cout<<0<<endl;
            }
        }
        else if(command==9){
            cin>>num;
            if (num<sets.size()){
                if (sets[num].length!=0){
                    sets[num].Print();
                }
                else if (sets[num].length==0){
                    cout<<endl;
                }
            
            }
            else{
                cout<<endl;
            }

        }
    }
    return 0;
}