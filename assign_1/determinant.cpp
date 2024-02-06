#include <iostream>
#include <vector>
using namespace std;

const int MAX_SIZE = 10;

// Function to calculate determinant of higher order matrix recursively
int determinantOfMatrix(vector<vector<int> > matrix, int n){
        // code here 
        if(n==1)
        {
            return matrix[0][0];
        }
        else if(n==2)
        {
            return (matrix[0][0]*matrix[1][1])-(matrix[0][1]*matrix[1][0]);
        }
        else
        {
            int finalans=0;
            for(int m=0;m<n;m++)
            {
                int multiplicand=matrix[0][m];
                
                if(multiplicand==0)
                continue;
                
                vector<vector<int>> mat;
                for(int i=1;i<n;i++)
                {
                    vector<int> temp;
                    for(int j=0;j<n;j++)
                    {
                        if(j==m)
                        continue;
                        
                        temp.push_back(matrix[i][j]);
                    }
                    mat.push_back(temp);
                }
                if(m%2==0)
                finalans+=(multiplicand*determinantOfMatrix(mat,n-1));
                else
                finalans-=(multiplicand*determinantOfMatrix(mat,n-1));
            }
            return finalans;
        }
    }

int main() {
    int n;
    cin>>n;
    vector<vector<int>> matrix(n);
    
    for(int i=0;i<n;i++){
    	matrix[i].assign(n,0);
    	for(int j=0;j<n;j++){
    		cin>>matrix[i][j];
    	}
    }
    
    int res = determinantOfMatrix(matrix,n);
    cout<<res<<endl;

    return 0;
}

