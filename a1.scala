object a1
{
	def binSearch(nos:Array[Int],srno:Int,l:Int,r:Int):Int=
	{
		var mid=(l+r)/2
		if(l>r)
		{
			return -1
		}
		else if(srno==nos(mid))
		{
			return mid
		}
		else if(l>r)
		{
			binSearch(nos,srno,l,mid-1)
		}
		else if(l>r)
		{
			binSearch(nos,srno,mid+1,r)
		}
	}
	def main(args:Array[String])
	{
		println("Enter Count:")
		var n:Int=Console.readInt
		var nos=new Array[Int](n)
		println("Enter Elements:")
		for(i<- 0 to n-1)
		{
			nos(i)=Console.readInt
		}
		nos=nos.sorted
		println("Number to be Searched:")
		var srno:Int=Console.readInt
		var pos:Int=binSearch(nos,srno,0,n-1)
		if(pos == -1)
		{
			println("Not Found!!")
		}
		else
		{
			println("Found at:"+(pos+1))
		}	
	}
}
