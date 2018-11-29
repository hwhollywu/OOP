std::ostream& Blockchain::
print(ostream& out) const {
	SPtr t = p;
	// TO-DO: reversely print out
	while(t.get() != nullptr){
		out << " [" << t.get()->blkLevel() <<","<<t.get()->serialId()<<"]";
		t = t.get()->last();
	}
	return out;
}