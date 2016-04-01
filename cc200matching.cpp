//
//
//
//
int isMatch(string s, string p)
{
  int i = 0, j = 0,i_recpos = 0, j_recpos = 0;

  int foundstar = 0;
  while (i < (int)s.length() )
  {
    if  (j < p.length() && ( (s[i] == p[j]) || (p[j] == '?') ) )
    {
      i++;
      j++;
    } 
    else if (j < p.length() && p[j] == '*')
    {
      foundstar = 1;
      i_recpos = i;
      j_recpos = j++;
    }
    else
    {
      if (foundstar == 0)
      {
        return 0;
      }
      else
      {
        i = i_recpos++;
        j = j_recpos + 1;
      }
    }
  }


  while (j < (int)p.length() && p[j] == '*')
  {
    j++;
  }
  return (j == (p.length()));
}

//isMatch("aa", "a") ¡ false
//isMatch("aa", "aa") ¡ true
//isMatch("aaa", "aa") ¡ false
//isMatch("aa", "*") ¡ true
//isMatch("aa", "a*") ¡ true
//isMatch("ab", "?*") ¡ true
//isMatch("aab", "c*a*b") ¡ false

void test_isMatch()
{
  int ret1 = isMatch("aa", "a");
  int ret2 = isMatch("aa", "aa");
  int ret3 = isMatch("aaa", "aa");
  int ret4 = isMatch("aa", "*");
  int ret5 = isMatch("aa", "a*");
  int ret6 = isMatch("aa", "?*");
  int ret7 = isMatch("aa", "c*a*b");
}


int isMatch_rec_helper(string s, int i, string p, int j)
{
  if (j == p.length() )
  {
    return (i == s.length());
  }
  else if ( p[j] == '?')
  {
    if (i == s.length())
    {
      return 0;
    }
    return isMatch_rec_helper(s, i + 1, p, j + 1);
  }
  else if (p[j] == '*')
  {
    for (; i < s.length(); i++)
    {
      if (1 == isMatch_rec_helper(s, i, p, j + 1))
      {
        return 1;
      }
    }
    return isMatch_rec_helper(s, i, p, j + 1);
  }
  else if (i < s.length())
  {
    if (s[i] != p[j])
    {
      return 0;
    }
    return isMatch_rec_helper(s, i + 1, p, j + 1);
  }

  return 0;

}

int isMatch_rec(string s, string p)
{ 
  int i = 0, j = 0;
  return isMatch_rec_helper(s, i, p, j);
}

void test_isMatch_rec()
{
  int ret1 = isMatch_rec("aa", "a");
  int ret2 = isMatch_rec("aa", "aa");
  int ret3 = isMatch_rec("aaa", "aa");
  int ret4 = isMatch_rec("aa", "*");
  int ret5 = isMatch_rec("aa", "a*");
  int ret6 = isMatch_rec("aa", "?*");
  int ret7 = isMatch_rec("aa", "c*a*b");
}

int isRegMatch(string s, string p)
{
  if (p.length() == 0)
  {
    return (s.length() == 0);
  }

  if (p.length() == 1)
  {
    if (s.length() < 1) 
    {
      return 0;
    }
    else if (p[0] != s[0] && p[0] != '.')
    {
      return 0;
    }
    else
   {
     return isRegMatch(s.substr(1), p.substr(1));
   }
 }

  if ( p[1] != '*')
  {
    if (s.length() < 1)
    {
      return 0;
    }
    else if (p[0] != s[0] && p[0] != '.')
    { 
      return 0;
    }
    else
    {
      return isRegMatch(s.substr(1), p.substr(1));
    }
  }
  else
  {
    if (1 == isRegMatch(s, p.substr(2)))
    {
      return 1;
    }

    int i = 0;
    while (i < s.length() && s[i] == p[0] || p[0] == '.')
    {
      if (1 == isRegMatch(s.substr(i + 1), p.substr(2)))
      {
        return 1;
      }
      i++;
    }
  }
  return 0;
}

//isMatch("aa", "a") ¡ false
//isMatch("aa", "aa") ¡ true
//isMatch("aaa", "aa") ¡ false
//isMatch("aa", "a*") ¡ true
//isMatch("aa", ".*") ¡ true
//isMatch("ab", ".*") ¡ true
//isMatch("aab", "c*a*b") ¡ true

void test_isRegMatch()
{
  int ret1 = isRegMatch("aa", "a");
  int ret2 = isRegMatch("aa", "aa");
  int ret3 = isRegMatch("aaa", "aa");
  int ret4 = isRegMatch("aa", "a*");
  int ret5 = isRegMatch("aa", ".*");
  int ret6 = isRegMatch("ab", ".*");
  int ret7 = isRegMatch("aab", "c*a*b");
}


//  Text: a-z, A-Z, 0-9
//  Pattern: a-z, A-z, 0-9, +, *
//  + = 1 or more times
//  * = 0 or more times
//  
//  Pattern: a+b
//  Text: aab, b return true
//
//  Pattern: a+b*
//  Text: aab, aa  return true

//test("aab", "a+b");//true
//test("aab", "aab");//true
//test("aab", "aa*b");//true
//test("aab", "a+b*");//true
//test("aab", "aa+b");//true
//test("aab", "a+b+");//true
//test("aab", "a+b*");//true
//test("aab", "aaa+b");//false
//test("aab", "a+bb+");//false

int isTMatch(string s, string p)
{
  if (p.length() == 0)
  {
    return (0 == s.length());
  }
  else if (p.length() == 1)
  {
    if (s.length() < 1)
    {
      return 0;
    }
    if (s[0] == p[0])
    {
       return isTMatch(s.substr(1), p.substr(1));
    }
  }
  else if (p[1] == '+')
  {
    int i = 0;
    while ( i < s.length() && s[i] == p[0])
   {
     if (1 == isTMatch(s.substr(i+1), p.substr(2)))
     {
       return 1;
     }
     i++;
   }
  }
  else if (p[1] == '*')
  {
    if (1 == isTMatch(s, p.substr(2)))
    {
       return 1;
     }

    int i = 0;
    while (i < s.length() && s[i] == p[0])
    {
       if (1 == isTMatch(s.substr(i+1), p.substr(2)))
       {
         return 1;
       }
      i++;
    }
  }
  else if (s.length() > 0 && s[0] == p[0])
  {   
    return isTMatch(s.substr(1), p.substr(1));
  }

  return 0;

}

void test_isTMatch()
{
  int ret1 = isTMatch("aab", "a+b");
  int ret2 = isTMatch("aab", "aab");
  int ret3 = isTMatch("aab", "aa*b");
  int ret4 = isTMatch("aab", "a+b*");
  int ret5 = isTMatch("aab", "aa+b");
  int ret6 = isTMatch("aab", "a+b+");
  int ret7 = isTMatch("aab", "a+b*");
  int ret8 = isTMatch("aab", "aaa+b");
  int ret9 = isTMatch("aab", "a+bb+");

}

