package 해시;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;

class TrieNode {
    HashMap<Character, TrieNode> children;

    public TrieNode() {
        this.children = new HashMap<>();
    }
}

class Trie {
    TrieNode root;
    HashMap<String, Integer> hashMap;

    public Trie() {
        root = new TrieNode();
        hashMap = new HashMap<>();
    }

    public String insert(String nickname) {
        TrieNode node = root;
        StringBuilder alias = new StringBuilder();
        boolean isEndOfPrefix = false;

        if (hashMap.containsKey(nickname)) {
            hashMap.put(nickname, hashMap.get(nickname) + 1);
            return nickname + hashMap.get(nickname);
        } else {
            hashMap.put(nickname, 1);
        }

        for (char c : nickname.toCharArray()) {
            if (!isEndOfPrefix) {
                alias.append(c);
            }
            if (node.children.containsKey(c)) {
                node = node.children.get(c);
            } else {
                isEndOfPrefix = true;
                node.children.put(c, new TrieNode());
                node = node.children.get(c);
            }
        }
        return alias.toString();
    }
}

public class Oct17_16934_GameNickname {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());

        Trie trie = new Trie();

        for (int i = 0; i < N; i++) {
            String nickname = br.readLine();
            bw.write(trie.insert(nickname));
            bw.newLine();
        }
        bw.flush();
        bw.close();
        br.close();
    }
}