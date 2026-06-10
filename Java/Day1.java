package Daywise;
/*n In Java we can create a String in this methods are ways
* -> But declaring the datatype as String  and assigning it the value or the data in the double courts eg:- String name =" Your Name"
* -> In this we will be using  "new" as  keyword to create a string eg:=String name = new String("Your name")
* -> We are having another methos this not an acytual offical methos but in some problrms we have to change the charecter into the string by this methos we will be changing it into an string
* eg:-char[] charArray = {'J', 'a', 'v', 'a'}; String str4 = new String(charArray); {  By this we can create an charecter and convert into the string if it needed
* -> The major differnce among this are when create a string by the first method then in our memory it will allcate the space if we create a new variable with smae data then we can see that 2 varaibles
* address will be same such that the system can work efficently
* but when use new keyword then it will auto matically allocates the new storage in the memory whether it has be present in the memory or not
* and in charecter to string first we will be declaring the chrecter and converting into the String if there is any problems in it
* like this we will be intilizing and declaring the Strings in the java */
/*----------------------------------------------------------------------------
  Now we know to know what are the properties of Strings are present in java and how can we use them in thw java
  -> length():- is used to get the number of charecter length or the length of the String eg:= int n = name.length();//lengtrh of the String
  ->CharAt():- it is used get what is present in the specific index of the string example if we want to get the first index of String then we need to use this eq:-Sop(name.charAt(0));
  Like this we will be using this base things in the java
  ->indexOf(String str): Starting at a specific character or word position in a string-1contains
  ->(CharSequence s): Checks ( trueor falsereturns) whether a specific word or character string is present in the main string.
  ->startsWith(String prefix)/ endsWith(String suffix): Checks whether the string begins or ends with a specific word.
   * ------------------------------------------------------------------------------------
    For comparision :--
    ->equals(Object obj): Checks whether the text inside two strings is exactly the same.
    ->equalsIgnoreCase(String anotherString): Ignoring case differencescompareTo
    ->(String anotherString): Compares two strings according to dictionary rules (Alphabetical order).
    For Modification :--
    ->substring(int beginIndex, int endIndex): Cuts a specific part from a larger string to create separate pieces or substrings.
    ->toLowerCase()/ toUpperCase(): Converts all characters in a string to lowercase or uppercase.
    ->trim(): Removes all unnecessary spaces at the beginning and end of the string.
    ->replace(char oldChar, char newChar): Replaces a specific character or word within a string with something new.
    -----------------------------------------------------------------------------------------------
    Joining and Spilting:--
    ->concat(String str): Appends another string to the end of a string (it +works the same as the operator).
    ->split(String regex): Breaks a large string into pieces based on a specific character (e.g. comma, space) and converts it into an array.
   */

import java.util.ArrayList;

public class Day1 {
    public static void main(String[] args){
        String paragraph = "Bold hit an bat";
         int j=0;
         while(j<paragraph.length()){
             char ch = paragraph.charAt(j);
             if(ch==32){
                 System.out.println();
                 j++;
                 continue;
             }
             System.out.print(ch);
             j++;
         }
    }
}
