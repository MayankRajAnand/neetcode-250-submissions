class Solution {
public:
    struct Node{
        Node* links[26];
        bool flag;

        Node(){
            for(int i=0;i<26;i++){
                links[i]=NULL;
            }
            flag=false;
        }

        bool isKeyPresent(char ch){
            return links[ch-'a']!=NULL;
        }

        Node* get(char ch){
            return links[ch-'a'];
        }

        void put(char ch, Node* node){
            links[ch-'a']=node;
        }

        void setEnd(){
            flag=true;
        }

        bool isEnd(){
            return flag==true;
        }

    };

    class Trie{
        private:
            Node* root;
        public:
            Trie(){
                root=new Node();
            }
            void insertWord(string word){
                Node* node=root;
                for(int i=0;i<word.size();i++){
                    if(!node->isKeyPresent(word[i])){
                        node->put(word[i], new Node());
                    }
                    node=node->get(word[i]);
                }
                node->setEnd();
            }

            int countChildrenAndReturnIndex(Node*node){
                int count=0;
                int index=0;
                for(int i=0;i<26;i++){
                   if(node->links[i]!=NULL){
                        count++;
                        index=i;
                   }
                }
                if(count>1)return -1;
                return index;
            }
            string lcp(){
            string ans="";
            Node* node=root;

            while(true){

                if(node->isEnd()) break;  

                int index=countChildrenAndReturnIndex(node);

                if(index==-1) break;

                char ch=index+'a';
                ans+=ch;
                node=node->get(ch);
            }

            return ans;  
        }


    };
    string longestCommonPrefix(vector<string>& strs) {
        Trie t;
        for(auto it:strs){
            t.insertWord(it);
        }

        return t.lcp();

    }
};