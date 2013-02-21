/**
 * This program simply does conversion from Two's Complement.
 * The two's-complement representation must be in 32-bit hex (8 hex digits).
 * For example, 0xFFFFFFFF is -1.
 *
 * Two's-complement is the most common method of internally representing signed
 * integers on computers. The two's complement of a binary number is defined as
 * the value obtained by subtracting the number from a large power of two.
 *
 * NOTE: This conversion can be done in one line: Integer.decode("0xHexnumber");
 *       This program is written for educational purposes, not production.
 *
 * For further reading, see Thomas Finley's tutorial on two's-complement:
 * http://www.cs.cornell.edu/~tomf/notes/cps104/twoscomp.html
 *
 * Elizabeth Johnson also has some good examples:
 * http://www.cs.xu.edu/csci210/02f/day10/slide4.html
 *
 * Name: Dennis Ideler
 * Date: Sept 25-26, 2008
 * Course: COSC 2P12 - Computer Organization and Assembly Language
 * Part of assignment 1 (there was also a written section).
 */
  
import java.io.*;

public class Converter
{
  /**
   * Constructor reads in user input and converts it, then repeats.
   */
  public Converter()
  {
    while (true)
    {
      System.out.print("\nPlease enter the internal representation (in 32-bit hexadecimal).\n> 0x");
  
      String twosCompInHex = "";

      for (int i = 0; i < 9; i++) // Read in 8 digits plus newline character.
      {
        try
        {
          char c = (char) System.in.read();
          if (c == '\n') continue;
          twosCompInHex += c;
        }
        catch (IOException e) { e.printStackTrace(); }
      }

      char msb = twosCompInHex.charAt(0);  // Most Significant Bit (MSB).
      long result;

      if ((int) msb >= 0 && (int) msb <= 8)  // Positive? Convert.
        result = convert(twosCompInHex);
      else  // Negative? Flip and subtract before converting.
        result = flipNsub(twosCompInHex);

      System.out.println(twosCompInHex + " (base 16) = " + result + " (base 10)");
    }
  }
	
	
  /**
   * Converts the 2's complement number in base 16 to base 10.
   * Starts at the Least Significant Bit (LSB), i.e. rightmost bit.
   */
  public long convert(String twosCompInHex)
  {
    long total = 0;

    for (int i = 7, j = 0; i >= 0; i--, j++)
      total += hex2dec(twosCompInHex.charAt(i)) * Math.pow(16, j);

    return total;
  }
	
	
  /**
   * Complements the hexadecimal value by flipping it.
   * Then converts the flipped value to decimal.
   * Then makes it negative and subtracts one.
   */
  private long flipNsub(String twosCompInHex)
  {
    String twosCompInHexFlipped = "";

    // Complement the value (flip it)
    for (int i = 0; i < 8; i++)
      twosCompInHexFlipped += 15 - hex2dec(twosCompInHex.charAt(i)); 

    long total = convert(twosCompInHexFlipped);
    total *= -1;
    total--;

    return total;	
  }
	
	
  /**
   * Takes in a single hexadecimal digit and returns the decimal value.
   * Returns -1 on error.
   */
  public static int hex2dec(char c)
  {
    if (c >= 'a' && c <= 'z')
      return (int) Integer.parseInt("" + (int) (c - 'a' + 10));

    if (c >= 'A' && c <= 'Z')
      return (int) Integer.parseInt("" + (int) (c - 'A' + 10));

    if (c >= '0' && c <= '9')
      return (int) Integer.parseInt("" + (char) c);

    return -1;
  }
	
  public static void main (String[] args) { new Converter(); }
}
