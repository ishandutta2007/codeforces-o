import java.io.*;
import java.text.*;
import java.util.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public void run() throws Exception {
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		String s = f.readLine();
		System.out.println(s.contains("0000000") || s.contains("1111111") ? "YES" : "NO");
	}
}