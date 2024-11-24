#include <iostream>
#include <string.h>

using namespace std;

long long int sch[5][3];

int main(){
    int tc;
    long long int d, m, y, h, mi, s;
    int tcc = 1;

    cin >> tc;

    while(tc--) {

      // memset(sch,0,sizeof(sch));
      for (int i = 0; i < 5; ++i)
      {
      for (int j = 0; j < 3; ++j)
      { 
        sch[i][j] = 0;
      }
      }

      for (int i = 0; i < 4; ++i){
            cin >> d >> m >> y >> h >> mi >> s;
            y -= 3000;
            // cout << d << " " << m << " " << y << " " << h << " " << mi << " " << s << endl;
            sch[i][0] = (d*24*3600) + (m*50*24*3600) + ( y*20*50*24*3600) + (h*3600) + (mi*60) + s;
            
            cin >> d >> m >> y >> h >> mi >> s;
            y -= 3000;
            //cout << d << " " << m << " " << y << " " << h << " " << mi << " " << s << endl;
            sch[i][1] = (d*24*3600) + (m*50*24*3600) + (y*20*50*24*3600) + (h*3600) + (mi*60) + s;
            //ut << "ttt " << sch[i][0] << " " << sch[i][1] << endl; 
            // cout << sch[i][0] << " " <<  sch[i][1] << endl;
      }

      // for (int i = 0; i < 4; ++i)
      // {
      //  cout << "q " << sch[i][0] << " " << sch[i][1] << endl; 
      // }
    
      long long int mulai = sch[3][0];  
      long long int selesai = sch[3][1];

      bool but = true;

      for (int i = 0; i < 3; ++i){
      
        if( mulai >=  sch[i][0] && mulai <= sch[i][1]){
        // cout << "sxa " << endl; 
        cout << " !!! " << mulai  << " " << selesai << " " << sch[i][0] << " " << sch[i][1] << endl;
        cout << "Case #" << tcc << ": COLLIDE" << endl; 
        but = false;
        break;
      }

      if(selesai >= sch[i][0] && selesai <= sch[i][1]){
        cout << "Case #" << tcc << ": COLLIDE" << endl; 
        but = false;
        break;
      }
      }

      if(but){
      cout << "Case #" << tcc << ": OK" << endl; 
      }

      tcc++;
    }
    return 0;
}