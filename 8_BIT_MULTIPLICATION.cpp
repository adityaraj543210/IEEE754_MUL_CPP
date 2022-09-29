#include <bits/stdc++.h>
#include <strings.h>
using namespace std;

//ieee 754
string toBinary(int a)
{
    string s = "";
    while (a)
    {
        s += (a % 2) + '0';
        a /= 2;
    }
    while(s.size() < 8)
        s+='0';
    reverse(s.begin(), s.end());
    return s;
}

string addBinary(string num1, string num2)
{
    // idea is that we want always to keep num1 as smaller one

    if (num1.size() > num2.size())
        return addBinary(num2, num1);

    // now calculating the difference
    int diff = num2.size() - num1.size();

    string padding;
    for (int i = 0; i < diff; i++)
        padding.push_back('0');

    num1 = padding + num1;
    string res;
    int carry = 0;
    int n = num1.size();

    for (int i = n - 1; i >= 0; i--)
    {
        if (num1[i] == '1' && num2[i] == '1')
        {
            if (carry == 1)
                res.push_back('1');
            else
                res.push_back('0');
            carry = 1;
        }

        else if (num1[i] == '0' && num2[i] == '0')
        {
            if (carry == 1)
                res.push_back('1');
            else
                res.push_back('0');
            carry = 0;
        }
        else
        {
            if (carry == 0)
            {
                res.push_back('1');
                carry = 0;
            }
            else
            {
                res.push_back('0');
                carry = 1;
            }
        }
    }

    if (carry == 1)
        res.push_back('1');

    reverse(res.begin(), res.end());

    return res;
}

string prodBinary(string num1, string num2)
{
    // string res(16,'0');
    int diff1=16-num1.size();
    string padd1(diff1,'0');
    int diff2=16-num2.size();
    string padd2(diff2,'0');
    num1=padd1+num1;
    num2=padd2+num2;

    vector<string> vec(16,string(32,'0'));

    for(int i=15; i>=0; i--)
    {
        if(num2[15-i]=='0')
            {
                vec[15-i]=string(32,'0');
            }
        
        else
        {
            int idx=15;
            for(int j=31-i; j>=16-i; j--)
            {
                vec[15-i][j]=num1[idx];
                idx--;
            }
        }
        
    }

    string sum=vec[0];
    for(int i=1; i<=15; i++)
    {
        sum=addBinary(vec[i],sum);
    }
    cout<<"Binary Product is: "<<endl;
return sum;
    
}


int main()
{
    float a1, b1,a,b;
    cout << "Please Enter the First Floating Point No: ";
    cin >> a1;
    cout << "Please Enter the Second Floating Point No: ";
    cin >> b1;
    a=abs(a1),b=abs(b1);

   int int_a,int_b;
   float frac_a,frac_b;
   
   int_a=floor(a), int_b=floor(b);
   frac_a=a-int_a,frac_b=b-int_b;
   
   frac_a=frac_a*256;
   frac_b=frac_b*256;

   int frac_a1=(int)frac_a,frac_b1=(int)frac_b;
  
   string mul1=toBinary(int_a)+toBinary(frac_a1);
   string mul2=toBinary(int_b)+toBinary(frac_b1);
  
  //printing input number
  if(a1<0)
    cout<<"First No: "<<'-'+toBinary(int_a)+'.'+toBinary(frac_a1)<<endl;
  else 
    cout<<"First No: "<<toBinary(int_a)+'.'+toBinary(frac_a1)<<endl;
  if(b1<0)
    cout<<"Second No: "<<'-'+toBinary(int_b)+'.'+toBinary(frac_b1)<<endl;
  else  cout<<"Second No: "<<toBinary(int_b)+'.'+toBinary(frac_b1)<<endl;

   string ansTemp=prodBinary(mul1,mul2);
   string ans=ansTemp.substr(0,16)+'.'+ansTemp.substr(16,16);

    cout<<"Decimal Product: ";
   if((a1<0 && b1>0) || (a1>0 && b1<0))
      cout<<'-'+ans<<endl;
   else  cout<<ans<<endl;
    return 0;
}