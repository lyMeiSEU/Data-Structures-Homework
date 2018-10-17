struct Ss
{
	int size;
	int start;
}

SparseMatrix SparseMatrix::FastTranspose()
{
	SparseMatrix b(cols,rows,terms);
	if(terms>0)
	{
		int i;
		Ss *row=new Ss[cols];
		fill(row.size,row.size+cols,0);
		for(i=1;i<cols;i++)
			row[smArray[i].cols].size++;
		row[0].start=0;
		for(i=0,i<terms;i++)
		{
			int j=row[smArray[i].col].start;
			b.smArray[j].row=smArray[i].col;
			b.smArray[j].col=smArray[i].row;
			b.smArray[j].value=smArray[i].value;
			row[smArray[i].col].start++;
		}
		delete[]row;
	}
	return b;
}