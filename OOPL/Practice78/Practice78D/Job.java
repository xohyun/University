//��ǻ���а� 20170988 �Ѽ���
public class Job implements Runnable {
	String name;
	public Job(String name) {
		this.name = name;
	}
	public void run() {
		int n = 0;
		while(true) {
			System.out.print(name + n++ + "\t");
			if ((n + 1) % 10 == 1){
				System.out.println();
			}
			if (n == 200) {
				break;
			}
		}
	}
}
