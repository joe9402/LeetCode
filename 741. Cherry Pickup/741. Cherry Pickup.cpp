//1. ����Ž�� : �ð��ʰ� :
//  ����Ž���� �� ��� �ð����⵵�� O(2^(2N)) ����
//  N 20���ʰ��ص� 10^12 ���� �ſ� Ŀ����.
//2. greedy : Ʋ�� :
//  greedy �ϰ� �������� �ִ� , ���ƿ��� �ִ��� ������ ���
//  ���ض�� ���� ������� �ʴ´�.
//3. dp : Ǯ��
//idea : �Ѹ��� ���� ���� �Ͱ� �ѹ��� �� ���� ���� ���� ����.
//a,b �� �� ����̶� �Ҷ�
//dp(a,b)�� a,b�� �ش� ��ġ���� N-1,N-1 ���� ü���� ������ ���� �ִ밪�̴�.
//���ǻ��� :
//1. ��ġ�� ��ġ�� ��� : �Ѹ� ���� �߰��Ѵ�.
//2. N-1,N-1 �� �������� ���ϴ� ��� : 
//  ����Ȳ���� dp return�� �ſ� ū ������ �ָ�
//  dp�� ��������� max�� Ȯ���Ҷ� ������ �ſ� ū ������ �����ϰ� �Ǿ�
//  ���������� ������ return �Ѵ�.


class Solution {
public:
    int map[51][51][51][51];
    int N;
    int cherryPickup(vector<vector<int>>& grid) {
        N = grid.size();
        for(int i =0;i<N;i++){ for(int j =0;j<N;j++){
            for(int k =0;k<N;k++){for(int l =0;l<N;l++){
             map[i][j][k][l] = -1;   
            }}
        }}
        return max(0,dp(grid,0,0,0,0));
    }
    
    int dp(vector<vector<int>>& grid,int x1,int y1,int x2,int y2){
        int res = 0;
        if(x1 >= N || y1 >=N || x2>=N || y2 >= N || grid[x1][y1] == -1 || grid[x2][y2] == -1)return -99999999;
        if(map[x1][y1][x2][y2] != -1) return map[x1][y1][x2][y2];
        if(x1 == N-1 && y1 == N-1) return grid[x1][y1]; 
        
        if(x1 == x2)res += grid[x1][y1];
        else res += grid[x1][y1] + grid[x2][y2];
        res += max(max(dp(grid,x1+1,y1,x2+1,y2), dp(grid,x1,y1+1,x2+1,y2)),
                   max(dp(grid,x1+1,y1,x2,y2+1), dp(grid,x1,y1+1,x2,y2+1)));
        map[x1][y1][x2][y2] = res;
        
        return res;
    }
    
};