package net.tcdw.ai;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {
        while (true) {
            try {
                readOnce();
            } catch (IOException e) {
                e.printStackTrace();
                System.exit(1);
            }
        }
    }

    private static void readOnce() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("> ");
        String[] 修饰词语 = {"呀", "啊", "哇", ""};
        String 用户输入 = br.readLine().strip();
        char 倒数第一 = 用户输入.charAt(用户输入.length() - 1);
        char 倒数第二 = 用户输入.charAt(用户输入.length() - 2);
        if (用户输入.substring(0, 2).equals("再见")) {
            System.out.println("再见！");
            System.exit(0);
        }
        if (倒数第一 == '？' || 倒数第一 == '?') {
            char 替换决定 = (用户输入.charAt(0) == '你') ? '我' : 用户输入.charAt(0);
            int 削减量 = (倒数第二 == '吗' || 倒数第二 == '嘛') ? 2 : 1;
            int 使用哪种修饰词语 = (int) Math.floor(Math.random() * 修饰词语.length);
            System.out.println(替换决定 + 用户输入.substring(1, 用户输入.length() - 削减量) + 修饰词语[使用哪种修饰词语] + '！');
        } else {
            System.out.println(用户输入);
        }
    }
}
