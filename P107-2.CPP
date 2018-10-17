	FastTranspose()的O(terms+cols)空间:构造SparseMatrix b(cols,rows,terms)。
		在构造SparseMatrix b(cols,rows,terms)时可以遍历并将每一项的row和col赋值为相应的i,j。
		并读取smArray中i=j的项直接赋值给相应的b。这样变为O(terms+cols-min{rows,cols})对于时间需求有较大改善