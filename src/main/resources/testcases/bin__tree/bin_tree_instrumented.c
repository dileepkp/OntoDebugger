#include <stdio.h>
#include <malloc.h>
typedef struct TREE {
int data;
struct TREE *left;
struct TREE *right;
}
TREE;

FILE *yyfp;

int yyseq = 1;

int main() {
yyfp = fopen("/home/aidb/Dropbox/testcases/bin_tree_trace.ttl","w");

int data,depth;

TREE *tree =NULL;
TREE *InsertTree(int data,TREE *p);
TREE *PrintTreeTriangle(TREE *tree, int level);
int TreeDepth(TREE *tree,int *depth,int level);
 fprintf( yyfp, "zzzfile0:10_1_10_14 pa:hasState file0:10_1_10_14_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:10_1_10_14_state-%d pa:hasValue %d\n", yyseq, depth);
 fprintf( yyfp, "zzzfile0:10_1_10_14_state-%d pa:atProgramPoint file0:15_7_15_7-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:15_7_15_7-%d pa:beforeStatement file0:15_7_15_7\n", yyseq);
 fprintf( yyfp, "zzzfile0:15_7_15_7-%d pa:timeStamp %d\n" , yyseq, yyseq);

while(1) {
printf("\nKey to insert|");
scanf("%d", &data);
 fprintf( yyfp, "zzzfile0:10_1_10_8 pa:hasState file0:10_1_10_8_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:10_1_10_8_state-%d pa:hasValue %d\n", yyseq, data);
 fprintf( yyfp, "zzzfile0:10_1_10_8_state-%d pa:atProgramPoint file0:18_1_19_6-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:18_1_19_6-%d pa:beforeStatement file0:18_1_19_6\n", yyseq);
 fprintf( yyfp, "zzzfile0:18_1_19_6-%d pa:timeStamp %d\n" , yyseq, yyseq);

if (data==0){
 fprintf( yyfp, "zzzfile0:10_1_10_8 pa:hasState file0:10_1_10_8_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:10_1_10_8_state-%d pa:hasValue %d\n", yyseq, data);
 fprintf( yyfp, "zzzfile0:10_1_10_8_state-%d pa:atProgramPoint file0:19_1_19_6-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:19_1_19_6-%d pa:beforeStatement file0:19_1_19_6\n", yyseq);
 fprintf( yyfp, "zzzfile0:19_1_19_6-%d pa:timeStamp %d\n" , yyseq, yyseq);

break;
}
tree =InsertTree(data,tree);
 fprintf( yyfp, "zzzfile0:10_1_10_8 pa:hasState file0:10_1_10_8_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:10_1_10_8_state-%d pa:hasValue %d\n", yyseq, data);
 fprintf( yyfp, "zzzfile0:10_1_10_8_state-%d pa:atProgramPoint file0:21_1_21_29-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:11_1_11_10 pa:hasState file0:11_1_11_10_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:11_1_11_10_state-%d pa:hasValue %lu\n", yyseq, tree);
 fprintf( yyfp, "zzzfile0:11_1_11_10 pa:hasStructDeclRef null \n");
 fprintf( yyfp, "zzzfile0:11_1_11_10_state-%d pa:atProgramPoint file0:21_1_21_29-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:21_1_21_29-%d pa:beforeStatement file0:21_1_21_29\n", yyseq);
 fprintf( yyfp, "zzzfile0:21_1_21_29-%d pa:timeStamp %d\n" , yyseq, yyseq);

printf("\n Tree Display;\n");
PrintTreeTriangle(tree,1);
 fprintf( yyfp, "zzzfile0:11_1_11_10 pa:hasState file0:11_1_11_10_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:11_1_11_10_state-%d pa:hasValue %lu\n", yyseq, tree);
 fprintf( yyfp, "zzzfile0:11_1_11_10 pa:hasStructDeclRef null \n");
 fprintf( yyfp, "zzzfile0:11_1_11_10_state-%d pa:atProgramPoint file0:23_1_23_8-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:23_1_23_8-%d pa:beforeStatement file0:23_1_23_8\n", yyseq);
 fprintf( yyfp, "zzzfile0:23_1_23_8-%d pa:timeStamp %d\n" , yyseq, yyseq);

depth=0;
 fprintf( yyfp, "zzzfile0:10_1_10_14 pa:hasState file0:10_1_10_14_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:10_1_10_14_state-%d pa:hasValue %d\n", yyseq, depth);
 fprintf( yyfp, "zzzfile0:10_1_10_14_state-%d pa:atProgramPoint file0:24_1_24_25-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:24_1_24_25-%d pa:beforeStatement file0:24_1_24_25\n", yyseq);
 fprintf( yyfp, "zzzfile0:24_1_24_25-%d pa:timeStamp %d\n" , yyseq, yyseq);

TreeDepth(tree,&depth,0);
 fprintf( yyfp, "zzzfile0:10_1_10_14 pa:hasState file0:10_1_10_14_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:10_1_10_14_state-%d pa:hasValue %d\n", yyseq, depth);
 fprintf( yyfp, "zzzfile0:10_1_10_14_state-%d pa:atProgramPoint file0:25_1_25_35-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:11_1_11_10 pa:hasState file0:11_1_11_10_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:11_1_11_10_state-%d pa:hasValue %lu\n", yyseq, tree);
 fprintf( yyfp, "zzzfile0:11_1_11_10 pa:hasStructDeclRef null \n");
 fprintf( yyfp, "zzzfile0:11_1_11_10_state-%d pa:atProgramPoint file0:25_1_25_35-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:25_1_25_35-%d pa:beforeStatement file0:25_1_25_35\n", yyseq);
 fprintf( yyfp, "zzzfile0:25_1_25_35-%d pa:timeStamp %d\n" , yyseq, yyseq);

printf("\nTree Depth =%d\n",depth);
}
return(0);
}

TREE *InsertTree(int data,TREE *p) {
if(!p) {
p=(TREE*)malloc(sizeof(TREE));
 fprintf( yyfp, "zzzfile0:29_33_29_33 pa:hasState file0:29_33_29_33_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:29_33_29_33_state-%d pa:hasValue %lu\n", yyseq, p);
 fprintf( yyfp, "zzzfile0:29_33_29_33 pa:hasStructDeclRef null \n");
 fprintf( yyfp, "zzzfile0:29_33_29_33_state-%d pa:atProgramPoint file0:32_1_32_13-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:32_1_32_13-%d pa:beforeStatement file0:32_1_32_13\n", yyseq);
 fprintf( yyfp, "zzzfile0:32_1_32_13-%d pa:timeStamp %d\n" , yyseq, yyseq);

p->data=data;
 fprintf( yyfp, "zzzfile0:29_22_29_25 pa:hasState file0:29_22_29_25_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:29_22_29_25_state-%d pa:hasValue %d\n", yyseq, data);
 fprintf( yyfp, "zzzfile0:29_22_29_25_state-%d pa:atProgramPoint file0:33_1_33_13-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:4_1_4_8 pa:hasState file0:4_1_4_8_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:4_1_4_8_state-%d pa:hasValue %d\n", yyseq, p->data);
 fprintf( yyfp, "zzzfile0:4_1_4_8_state-%d pa:atProgramPoint file0:33_1_33_13-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:33_1_33_13-%d pa:beforeStatement file0:33_1_33_13\n", yyseq);
 fprintf( yyfp, "zzzfile0:33_1_33_13-%d pa:timeStamp %d\n" , yyseq, yyseq);

p->left=NULL;
 fprintf( yyfp, "zzzfile0:5_1_5_17 pa:hasState file0:5_1_5_17_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:5_1_5_17_state-%d pa:hasValue %lu\n", yyseq, p->left);
 fprintf( yyfp, "zzzfile0:5_1_5_17 pa:hasStructDeclRef ftp://home/demo/Dropbox/testcases/bin_tree.c#29_33_29_33 \n");
 fprintf( yyfp, "zzzfile0:5_1_5_17_state-%d pa:atProgramPoint file0:34_1_34_14-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:34_1_34_14-%d pa:beforeStatement file0:34_1_34_14\n", yyseq);
 fprintf( yyfp, "zzzfile0:34_1_34_14-%d pa:timeStamp %d\n" , yyseq, yyseq);

p->right=NULL;
 fprintf( yyfp, "zzzfile0:6_1_6_18 pa:hasState file0:6_1_6_18_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:6_1_6_18_state-%d pa:hasValue %lu\n", yyseq, p->right);
 fprintf( yyfp, "zzzfile0:6_1_6_18 pa:hasStructDeclRef ftp://home/demo/Dropbox/testcases/bin_tree.c#29_33_29_33 \n");
 fprintf( yyfp, "zzzfile0:6_1_6_18_state-%d pa:atProgramPoint file0:35_1_35_10-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:35_1_35_10-%d pa:beforeStatement file0:35_1_35_10\n", yyseq);
 fprintf( yyfp, "zzzfile0:35_1_35_10-%d pa:timeStamp %d\n" , yyseq, yyseq);

return(p);
}
if(data < p->data){
 fprintf( yyfp, "zzzfile0:6_1_6_18 pa:hasState file0:6_1_6_18_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:6_1_6_18_state-%d pa:hasValue %lu\n", yyseq, p->right);
 fprintf( yyfp, "zzzfile0:6_1_6_18 pa:hasStructDeclRef ftp://home/demo/Dropbox/testcases/bin_tree.c#29_33_29_33 \n");
 fprintf( yyfp, "zzzfile0:6_1_6_18_state-%d pa:atProgramPoint file0:38_1_38_33-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:5_1_5_17 pa:hasState file0:5_1_5_17_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:5_1_5_17_state-%d pa:hasValue %lu\n", yyseq, p->left);
 fprintf( yyfp, "zzzfile0:5_1_5_17 pa:hasStructDeclRef ftp://home/demo/Dropbox/testcases/bin_tree.c#29_33_29_33 \n");
 fprintf( yyfp, "zzzfile0:5_1_5_17_state-%d pa:atProgramPoint file0:38_1_38_33-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:29_22_29_25 pa:hasState file0:29_22_29_25_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:29_22_29_25_state-%d pa:hasValue %d\n", yyseq, data);
 fprintf( yyfp, "zzzfile0:29_22_29_25_state-%d pa:atProgramPoint file0:38_1_38_33-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:4_1_4_8 pa:hasState file0:4_1_4_8_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:4_1_4_8_state-%d pa:hasValue %d\n", yyseq, p->data);
 fprintf( yyfp, "zzzfile0:4_1_4_8_state-%d pa:atProgramPoint file0:38_1_38_33-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:38_1_38_33-%d pa:beforeStatement file0:38_1_38_33\n", yyseq);
 fprintf( yyfp, "zzzfile0:38_1_38_33-%d pa:timeStamp %d\n" , yyseq, yyseq);

p->left=InsertTree(data,p->left);
}
else{
if(data > p->data){
 fprintf( yyfp, "zzzfile0:6_1_6_18 pa:hasState file0:6_1_6_18_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:6_1_6_18_state-%d pa:hasValue %lu\n", yyseq, p->right);
 fprintf( yyfp, "zzzfile0:6_1_6_18 pa:hasStructDeclRef ftp://home/demo/Dropbox/testcases/bin_tree.c#29_33_29_33 \n");
 fprintf( yyfp, "zzzfile0:6_1_6_18_state-%d pa:atProgramPoint file0:40_1_40_35-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:4_1_4_8 pa:hasState file0:4_1_4_8_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:4_1_4_8_state-%d pa:hasValue %d\n", yyseq, p->data);
 fprintf( yyfp, "zzzfile0:4_1_4_8_state-%d pa:atProgramPoint file0:40_1_40_35-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:29_22_29_25 pa:hasState file0:29_22_29_25_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:29_22_29_25_state-%d pa:hasValue %d\n", yyseq, data);
 fprintf( yyfp, "zzzfile0:29_22_29_25_state-%d pa:atProgramPoint file0:40_1_40_35-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:40_1_40_35-%d pa:beforeStatement file0:40_1_40_35\n", yyseq);
 fprintf( yyfp, "zzzfile0:40_1_40_35-%d pa:timeStamp %d\n" , yyseq, yyseq);

p->right=InsertTree(data,p->right);
}
}
return(p);
}

TREE *PrintTreeTriangle(TREE *tree, int level) {

int i;
if(tree) {
 fprintf( yyfp, "zzzfile0:4_1_4_8 pa:hasState file0:4_1_4_8_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:4_1_4_8_state-%d pa:hasValue %d\n", yyseq, tree->data);
 fprintf( yyfp, "zzzfile0:4_1_4_8_state-%d pa:atProgramPoint file0:46_1_46_39-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:43_41_43_45 pa:hasState file0:43_41_43_45_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:43_41_43_45_state-%d pa:hasValue %d\n", yyseq, level);
 fprintf( yyfp, "zzzfile0:43_41_43_45_state-%d pa:atProgramPoint file0:46_1_46_39-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:44_1_44_5 pa:hasState file0:44_1_44_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:44_1_44_5_state-%d pa:hasValue %d\n", yyseq, i);
 fprintf( yyfp, "zzzfile0:44_1_44_5_state-%d pa:atProgramPoint file0:46_1_46_39-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:6_1_6_18 pa:hasState file0:6_1_6_18_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:6_1_6_18_state-%d pa:hasValue %lu\n", yyseq, tree->right);
 fprintf( yyfp, "zzzfile0:6_1_6_18 pa:hasStructDeclRef ftp://home/demo/Dropbox/testcases/bin_tree.c#43_31_43_34 \n");
 fprintf( yyfp, "zzzfile0:6_1_6_18_state-%d pa:atProgramPoint file0:46_1_46_39-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:5_1_5_17 pa:hasState file0:5_1_5_17_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:5_1_5_17_state-%d pa:hasValue %lu\n", yyseq, tree->left);
 fprintf( yyfp, "zzzfile0:5_1_5_17 pa:hasStructDeclRef ftp://home/demo/Dropbox/testcases/bin_tree.c#43_31_43_34 \n");
 fprintf( yyfp, "zzzfile0:5_1_5_17_state-%d pa:atProgramPoint file0:46_1_46_39-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:43_31_43_34 pa:hasState file0:43_31_43_34_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:43_31_43_34_state-%d pa:hasValue %lu\n", yyseq, tree);
 fprintf( yyfp, "zzzfile0:43_31_43_34 pa:hasStructDeclRef null \n");
 fprintf( yyfp, "zzzfile0:43_31_43_34_state-%d pa:atProgramPoint file0:46_1_46_39-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:46_1_46_39-%d pa:beforeStatement file0:46_1_46_39\n", yyseq);
 fprintf( yyfp, "zzzfile0:46_1_46_39-%d pa:timeStamp %d\n" , yyseq, yyseq);

PrintTreeTriangle(tree->right,level+1);
 fprintf( yyfp, "zzzfile0:43_41_43_45 pa:hasState file0:43_41_43_45_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:43_41_43_45_state-%d pa:hasValue %d\n", yyseq, level);
 fprintf( yyfp, "zzzfile0:43_41_43_45_state-%d pa:atProgramPoint file0:47_1_47_15-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:6_1_6_18 pa:hasState file0:6_1_6_18_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:6_1_6_18_state-%d pa:hasValue %lu\n", yyseq, tree->right);
 fprintf( yyfp, "zzzfile0:6_1_6_18 pa:hasStructDeclRef ftp://home/demo/Dropbox/testcases/bin_tree.c#43_31_43_34 \n");
 fprintf( yyfp, "zzzfile0:6_1_6_18_state-%d pa:atProgramPoint file0:47_1_47_15-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:47_1_47_15-%d pa:beforeStatement file0:47_1_47_15\n", yyseq);
 fprintf( yyfp, "zzzfile0:47_1_47_15-%d pa:timeStamp %d\n" , yyseq, yyseq);

printf("\n\n");
 fprintf( yyfp, "zzzfile0:44_1_44_5 pa:hasState file0:44_1_44_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:44_1_44_5_state-%d pa:hasValue %d\n", yyseq, i);
 fprintf( yyfp, "zzzfile0:44_1_44_5_state-%d pa:atProgramPoint file0:48_10_48_16-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:43_41_43_45 pa:hasState file0:43_41_43_45_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:43_41_43_45_state-%d pa:hasValue %d\n", yyseq, level);
 fprintf( yyfp, "zzzfile0:43_41_43_45_state-%d pa:atProgramPoint file0:48_10_48_16-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:48_10_48_16-%d pa:beforeStatement file0:48_10_48_16\n", yyseq);
 fprintf( yyfp, "zzzfile0:48_10_48_16-%d pa:timeStamp %d\n" , yyseq, yyseq);

for (i=0;i<level;i++){
 fprintf( yyfp, "zzzfile0:43_41_43_45 pa:hasState file0:43_41_43_45_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:43_41_43_45_state-%d pa:hasValue %d\n", yyseq, level);
 fprintf( yyfp, "zzzfile0:43_41_43_45_state-%d pa:atProgramPoint file0:49_1_49_18-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:44_1_44_5 pa:hasState file0:44_1_44_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:44_1_44_5_state-%d pa:hasValue %d\n", yyseq, i);
 fprintf( yyfp, "zzzfile0:44_1_44_5_state-%d pa:atProgramPoint file0:49_1_49_18-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:49_1_49_18-%d pa:beforeStatement file0:49_1_49_18\n", yyseq);
 fprintf( yyfp, "zzzfile0:49_1_49_18-%d pa:timeStamp %d\n" , yyseq, yyseq);

printf("       ");
}
printf("%d",tree->data);
 fprintf( yyfp, "zzzfile0:4_1_4_8 pa:hasState file0:4_1_4_8_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:4_1_4_8_state-%d pa:hasValue %d\n", yyseq, tree->data);
 fprintf( yyfp, "zzzfile0:4_1_4_8_state-%d pa:atProgramPoint file0:51_1_51_38-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:51_1_51_38-%d pa:beforeStatement file0:51_1_51_38\n", yyseq);
 fprintf( yyfp, "zzzfile0:51_1_51_38-%d pa:timeStamp %d\n" , yyseq, yyseq);

PrintTreeTriangle(tree->left,level+1);
}
return(NULL);
}

int TreeDepth(TREE *tree,int *depth,int level) {
if(tree) {
if (level>*depth){
 fprintf( yyfp, "zzzfile0:55_31_55_35 pa:hasState file0:55_31_55_35_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:55_31_55_35_state-%d pa:hasValue %d\n", yyseq, depth);
 fprintf( yyfp, "zzzfile0:55_31_55_35_state-%d pa:atProgramPoint file0:58_1_58_13-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:55_41_55_45 pa:hasState file0:55_41_55_45_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:55_41_55_45_state-%d pa:hasValue %d\n", yyseq, level);
 fprintf( yyfp, "zzzfile0:55_41_55_45_state-%d pa:atProgramPoint file0:58_1_58_13-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:58_1_58_13-%d pa:beforeStatement file0:58_1_58_13\n", yyseq);
 fprintf( yyfp, "zzzfile0:58_1_58_13-%d pa:timeStamp %d\n" , yyseq, yyseq);

*depth=level;
}
TreeDepth(tree->left,depth,level+1);
 fprintf( yyfp, "zzzfile0:5_1_5_17 pa:hasState file0:5_1_5_17_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:5_1_5_17_state-%d pa:hasValue %lu\n", yyseq, tree->left);
 fprintf( yyfp, "zzzfile0:5_1_5_17 pa:hasStructDeclRef ftp://home/demo/Dropbox/testcases/bin_tree.c#55_21_55_24 \n");
 fprintf( yyfp, "zzzfile0:5_1_5_17_state-%d pa:atProgramPoint file0:60_1_60_37-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:55_31_55_35 pa:hasState file0:55_31_55_35_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:55_31_55_35_state-%d pa:hasValue %d\n", yyseq, depth);
 fprintf( yyfp, "zzzfile0:55_31_55_35_state-%d pa:atProgramPoint file0:60_1_60_37-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:55_41_55_45 pa:hasState file0:55_41_55_45_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:55_41_55_45_state-%d pa:hasValue %d\n", yyseq, level);
 fprintf( yyfp, "zzzfile0:55_41_55_45_state-%d pa:atProgramPoint file0:60_1_60_37-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:60_1_60_37-%d pa:beforeStatement file0:60_1_60_37\n", yyseq);
 fprintf( yyfp, "zzzfile0:60_1_60_37-%d pa:timeStamp %d\n" , yyseq, yyseq);

TreeDepth(tree->right,depth,level+1);
}
return(0);
}
