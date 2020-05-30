import java.io.BufferedReader;
import java.io.InputStreamReader;

//import for Scanner and other utility classes
import java.util.*;

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
class AlphaNumericException extends Exception{
    AlphaNumericException(String s)
    {
        super(s);
    }
}
class StringException extends Exception
{
    StringException(String s)
    {
        super(s);

    }
}
class Validator{
    boolean isValid(String s) throws Exception
    {
        try{
        int x =Integer.parseInt(s);

        return true;

        }
        catch(Exception e)
        {
            for(int i=0;i<10;i++)
            for(int j=0;j<s.length();j++)
            if(String.valueOf(i).charAt(0) == s.charAt(j))
            throw new AlphaNumericException("Its an AlphaNumeric");
            throw new StringException("Its a String");
        }
    
    }
}
class TestClass {
    public static void main(String args[] ) throws Exception {
       

        //BufferedReader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n;
        n = Integer.parseInt(br.readLine());
        Validator validator = new Validator();

        for(int i=0;i<n;i++)
        {
            try{
            String name = br.readLine();   
                    validator.isValid(name);
            System.out.println("Valid Format");
            }
            catch(Exception e)
            {
                System.out.println(e.getMessage());
            }   
                     }             // Reading input from STDIN
        

        // Write your code here

    }
}
