int paranthesisMatch(char *expr)
{
  //returns true if the paranthesis is matched!
  //else returns false
  struct stact* sp; // Creates an empty stack!
  for(i = 0; i != '\0'; ++i)
    {
      if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
	push(sp, expr[i]);
      else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']')
	{
	  if(isEmpty(sp))
	    return 0;
	  pop(sp);
	}
    }
  if(isEmpty(sp))
    return 1;
  else
    return 0;
}

