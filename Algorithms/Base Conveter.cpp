struct BaseInt
{
    string val;
    ll base;

    BaseInt() {}

    BaseInt(string _val, int _base = 10)            // Do check if any value if val is greater than base
    {
        val = _val;                                 // Which is impossible
        base = _base;
    }

    char reVal(int num)
    {
        if(num >= 0 && num <= 9)
            return (char)(num + '0');
        return (char)(num - 10 + 'A');
    }

    int getVal(char c)
    {
        if(c <= '9' && c >= '0')
            return c-'0';
        return c-'A'+10;
    }

    void DecimalTo(int _base)
    {
        ll v = atoll(val.c_str());
        base = _base;
        val.clear();
        while(v)
        {
            val.push_back(reVal(v%base));
            v /= base;
        }
        reverse(val.begin(), val.end());
        if(val.empty()) val.push_back('0');
    }

    bool ToDecimal()
    {
        ll ret = 0;
        for(int i = 0; i < (int)val.size(); ++i)
        {
            int v = getVal(val[i]);
            if(v >= base)       return 0;
            if(i)               ret *= base;
            ret += v;
        }
        val = to_string(ret);
        base = 10;
        return 1;
    }

    void ChangeBase(int to)
    {
        if(base == to)  return;             // If input is "000", then output will also be "000" (if base remains same)
        if(base != 10)  ToDecimal();        // remove the if statements to recover
        if(to != 10)    DecimalTo(to);
    }

    void Reverse()
    {
        reverse(val.begin(), val.end());
    }

    BaseInt operator + (BaseInt other) const
    {
        BaseInt a(val, base), b = other;
        a.ToDecimal();
        b.ToDecimal();
        string p1=a.val;
        string p2=b.val;
        string sum = to_string(atoi(p1.c_str()) + atoi(p2.c_str()));

        BaseInt ret(sum);
        ret.ChangeBase(base);
        return ret;
    }
};

