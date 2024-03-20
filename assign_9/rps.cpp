#include <iostream>
using namespace std;

class Tool {

public:

    int strength;
    char type;
    
    Tool() {}
    Tool(int s, char t) : strength(s), type(t) {}
    
    void setStrength(int s) {
        strength = s;
    }

    virtual bool fight(Tool opponent) {
        return false;
    }
};

class Rock : public Tool {
public:
    Rock(int s) : Tool(s, 'r') {}

    bool fight(Tool opponent) override {
        if (opponent.type == 's')
            return strength * 2 > opponent.strength;
        else 
            return strength > opponent.strength * 2;
    }
};

class Paper : public Tool {
public:
    Paper(int s) : Tool(s, 'p') {}

    bool fight(Tool opponent) override {
        if (opponent.type == 'r') 
            return strength * 2 > opponent.strength;
        else 
            return strength > opponent.strength * 2;
    }
};

class Scissors : public Tool {
public:
    Scissors(int s) : Tool(s, 's') {}

    bool fight(Tool opponent) override {
        if (opponent.type == 'p') 
            return strength * 2 > opponent.strength;
        else 
            return strength > opponent.strength * 2;
    }
};

int main() {
    int s1,s2,s3;
    cout<<"Enter strength of Scissor: "<<endl;
    cin>>s1;
    cout<<"Enter strength of Paper: "<<endl;
    cin>>s2;
    cout<<"Enter strength of Rock: "<<endl;
    cin>>s3;

    Scissors s(s1);
    Paper p(s2);
    Rock r(s3);
    
    if(s.fight(p)){
        cout<<"Scissor won"<<endl;
    }
    else{
        cout<<"Paper won"<<endl;
    }

    if(p.fight(r)){
        cout<<"Paper won"<<endl;
    }
    else{
        cout<<"Rock won"<<endl;
    }

    if(r.fight(s)){
        cout<<"Rock won"<<endl;
    }
    else{
        cout<<"Scissor won"<<endl;
    }
}