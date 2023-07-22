using System;
using System.Text;

class Program{
    static void Main(){
        StringBuilder sb = new StringBuilder();
        string[] ss = Console.ReadLine().Split();
        int n = int.Parse(ss[0]);
        int m = int.Parse(ss[1]);
        bool check = true;
        if(n==1)n++;
        for(int i=n;i<=m;i++){
            check=true;
            for(int j=2;j*j<=i;j++){
                if(i!=j&&i%j==0){
                    check=false;
                    break;
                }
            }
            if(check){
                sb.AppendLine(i.ToString());
            }
        }
        Console.Write(sb);
    }
}