	FastTranspose()��O(terms+cols)�ռ�:����SparseMatrix b(cols,rows,terms)��
		�ڹ���SparseMatrix b(cols,rows,terms)ʱ���Ա�������ÿһ���row��col��ֵΪ��Ӧ��i,j��
		����ȡsmArray��i=j����ֱ�Ӹ�ֵ����Ӧ��b��������ΪO(terms+cols-min{rows,cols})����ʱ�������нϴ����