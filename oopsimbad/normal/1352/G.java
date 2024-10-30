import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int asdf = f.nextInt();
		while(asdf-->0) {
			int n = f.nextInt();
			if(n < 4) out.print(-1);
			else if(n % 2 == 0) {
				for(int i = 2; i <= n; i+=2)
					out.print(i + " ");
				out.print(n-3 + " ");
				out.print(n-1 + " ");
				for(int i = n-5; i >= 1; i-=2)
					out.print(i + " ");
			} else {
				for(int i = 1; i <= n; i+=2)
					out.print(i + " ");
				out.print(n-3 + " ");
				out.print(n-1 + " ");
				for(int i = n-5; i >= 2; i-=2)
					out.print(i + " ");
				
			}
			out.println();
		}
		out.flush();
	}
    static class FastScanner {
        public BufferedReader reader;
        public StringTokenizer tokenizer;
        public FastScanner() {
            reader = new BufferedReader(new InputStreamReader(System.in), 32768);
            tokenizer = null;
        }
        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
        public int nextInt() {
            return Integer.parseInt(next());
        }
        public long nextLong() {
        	return Long.parseLong(next());
        }
        public double nextDouble() {
        	return Double.parseDouble(next());
        }
        public String nextLine() {
        	try {
        		return reader.readLine();
        	} catch(IOException e) {
        		throw new RuntimeException(e);
        	}
        }
    }
}