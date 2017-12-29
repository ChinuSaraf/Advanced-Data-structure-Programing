import java.util.*;

abstract class stack
{
	stack(){}
	abstract protected void push();
	abstract protected int pop(); 
	abstract protected int top();
	
	public final void function()
	{
		Scanner sc=new Scanner(System.in);
		int opt,flag=1;
		while(flag==1)
		{
			System.out.println("1.Push 2.Pop 3.Top 4.Exit");
			opt=sc.nextInt();
			switch(opt)
			{
				case 1:
					push();
					break;
				case 2:
					pop();
					break;
				case 3:
					top();
					break;
				case 4:
					flag=0;
					break;
			}
		}
	}
}

class Intstack extends stack
{
	private int st[]=new int[100];
	private int top=-1;
	protected void push()
	{
		int data;
		Scanner sc=new Scanner(System.in);
		RuntimeException re=new RuntimeException("Overflow");
		try
		{
			if(top==100)
			{
				throw re;
			}
			else
			{
				System.out.println("Enter data: ");
				data=sc.nextInt();
				st[++top]=data;
			}
		}
		catch(RuntimeException ret)
		{
			System.out.println("Exception caught "+ret);
		}
	}
	protected int pop()
	{
		RuntimeException re=new RuntimeException("Underflow");
		try
		{
			if(top==-1)
			{
				throw re;
			}
			else
			{
				System.out.println("Popped data: "+st[top]);
				top--;
				return 1;
			}
		}
		catch(RuntimeException ret)
		{
			System.out.println("Exception caught "+ret);
			return 0;
		}
	}
	protected int top()
	{
		int data;
		RuntimeException re=new RuntimeException("Underflow");
		try
		{
			if(top==-1)
			{
				throw re;
			}
			else
			{
				data=st[top];
				System.out.println("Stack top: "+data);
				return 1;
			}
		}
		catch(RuntimeException ret)
		{
			System.out.println("Exception caught "+ret);
			return 0;
		}
	}
}
class Charstack extends stack
{
	private char st[]=new char[100];
	private int top=-1;
	protected void push()
	{
		char data;
		Scanner sc=new Scanner(System.in);
		RuntimeException re=new RuntimeException("Overflow");
		try
		{
			if(top==100)
			{
				throw re;
			}
			else
			{
				System.out.println("Enter data: ");
				data=sc.next().charAt(0);
				st[++top]=data;
			}
		}
		catch(RuntimeException ret)
		{
			System.out.println("Exception caught "+ret);
		}
	}
	protected int pop()
	{
		RuntimeException re=new RuntimeException("Underflow");
		try
		{
			if(top==-1)
			{
				throw re;
			}
			else
			{
				System.out.println("Popped data: "+st[top]);
				top--;
				return 1;
			}
		}
		catch(RuntimeException ret)
		{
			System.out.println("Exception caught "+ret);
			return 0;
		}
	}
	protected int top()
	{
		char data;
		RuntimeException re=new RuntimeException("Underflow");
		try
		{
			if(top==-1)
			{
				throw re;
			}
			else
			{
				data=st[top];
				System.out.println("Stack top: "+data);
				return 1;
			}
		}
		catch(RuntimeException ret)
		{
			System.out.println("Exception caught "+ret);
			return 0;
		}
	}
}


public class temp
{
	public static void main(String args[])
	{
		System.out.println("---------------Integer Stack-------------------");
		stack s=new Intstack();
		s.function();
		
		System.out.println("---------------Character Stack-------------------");
		s=new Charstack();
		s.function();
	}
}		
