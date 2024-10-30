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
        ///
        int asdf = f.nextInt();
        while(asdf-->0) {
            int n = f.nextInt();
            int[] arr = new int[n];
            for(int i = 0; i < n; i++) arr[i] = f.nextInt();
            int l = 0, r = n;
            while(l < r) {
                int m = (l+r)/2;
                int ll = m, rr = n-1;
                int prev = 0;
                boolean ok = true;
                while(ll <= rr) {
                    if(arr[ll] < arr[rr]) {
                        if(prev > arr[ll]) ok = false;
                        prev = arr[ll];
                        ll++;
                    } else {
                        if(prev > arr[rr]) ok = false;
                        prev = arr[rr];
                        rr--;
                    }
                }
                if(ok) r = m;
                else l = m+1;
            }
            out.println(l);
        }
///
		out.flush();
	}
///
	static class FastScanner {
		public BufferedReader reader;
		public StringTokenizer tokenizer;
		public FastScanner() {
			reader = new BufferedReader(new InputStreamReader(System.in), 32768);
			tokenizer = null;
		}
		public String next() { while (tokenizer == null || !tokenizer.hasMoreTokens()) {
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