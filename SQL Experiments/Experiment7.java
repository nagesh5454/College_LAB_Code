
class BTreeNode {
    int[] keys;
    int t;  // Minimum degree
    BTreeNode[] children;
    int n;
    boolean leaf;

    public BTreeNode(int t, boolean leaf) {
        this.t = t;
        this.leaf = leaf;
        this.keys = new int[2 * t - 1];
        this.children = new BTreeNode[2 * t];
        this.n = 0;
    }

    public void traverse() {
        int i;
        for (i = 0; i < this.n; i++) {
            if (!this.leaf) {
                this.children[i].traverse();
            }
            System.out.print(" " + this.keys[i]);
        }
        if (!this.leaf) {
            this.children[i].traverse();
        }
    }

    public BTreeNode search(int k) {
        int i = 0;
        while (i < this.n && k > this.keys[i]) {
            i++;
        }
        if (i < this.n && this.keys[i] == k) {
            return this;
        }
        if (this.leaf) {
            return null;
        }
        return this.children[i].search(k);
    }

    public void insertNonFull(int k) {
        int i = this.n - 1;
        if (this.leaf) {
            while (i >= 0 && this.keys[i] > k) {
                this.keys[i + 1] = this.keys[i];
                i--;
            }
            this.keys[i + 1] = k;
            this.n++;
        } else {
            while (i >= 0 && this.keys[i] > k) {
                i--;
            }
            if (this.children[i + 1].n == 2 * this.t - 1) {
                splitChild(i + 1, this.children[i + 1]);
                if (this.keys[i + 1] < k) {
                    i++;
                }
            }
            this.children[i + 1].insertNonFull(k);
        }
    }

    public void splitChild(int i, BTreeNode y) {
        BTreeNode z = new BTreeNode(y.t, y.leaf);
        z.n = this.t - 1;
        for (int j = 0; j < this.t - 1; j++) {
            z.keys[j] = y.keys[j + this.t];
        }
        if (!y.leaf) {
            for (int j = 0; j < this.t; j++) {
                z.children[j] = y.children[j + this.t];
            }
        }
        y.n = this.t - 1;
        for (int j = this.n; j >= i + 1; j--) {
            this.children[j + 1] = this.children[j];
        }
        this.children[i + 1] = z;
        for (int j = this.n - 1; j >= i; j--) {
            this.keys[j + 1] = this.keys[j];
        }
        this.keys[i] = y.keys[this.t - 1];
        this.n++;
    }
}

class BTree {
    BTreeNode root;
    int t;

    public BTree(int t) {
        this.root = null;
        this.t = t;
    }

    public void traverse() {
        if (this.root != null) {
            this.root.traverse();
        }
    }

    public BTreeNode search(int k) {
        if (this.root == null) {
            return null;
        }
        return this.root.search(k);
    }

    public void insert(int k) {
        if (this.root == null) {
            this.root = new BTreeNode(this.t, true);
            this.root.keys[0] = k;
            this.root.n = 1;
        } else {
            if (this.root.n == 2 * this.t - 1) {
                BTreeNode s = new BTreeNode(this.t, false);
                s.children[0] = this.root;
                s.splitChild(0, this.root);
                int i = 0;
                if (s.keys[0] < k) {
                    i++;
                }
                s.children[i].insertNonFull(k);
                this.root = s;
            } else {
                this.root.insertNonFull(k);
            }
        }
    }
}

public class Experiment7 {
    public static void main(String[] args) {
        BTree t = new BTree(3);
        t.insert(10);
        t.insert(20);
        t.insert(5);
        t.insert(6);
        t.insert(12);
        t.insert(30);
        t.insert(7);
        t.insert(17);

        System.out.println("Traversal of the constructed tree is ");
        t.traverse();

        int k = 6;
        if (t.search(k) != null) {
            System.out.println("\nPresent");
        } else {
            System.out.println("\nNot Present");
        }
    }
}
