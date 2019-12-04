#include <mach-o/dyld.h>
#include <sys/stat.h> 
#include <sys/mman.h> 
#include <fcntl.h>


int main()
{
	NSObjectFileImage fileImage = NULL;
	NSModule module = NULL;
	NSSymbol symbol = NULL;

	struct stat stat_buf;
	void (*function)();

	int fd = open("test.bundle", O_RDONLY, 0);
	fstat(fd, &stat_buf);
	void* codeAddr = mmap(NULL, stat_buf.st_size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
	close(fd);


	NSCreateObjectFileImageFromMemory(codeAddr, stat_buf.st_size, &fileImage);
	
	module = NSLinkModule(fileImage, "module", NSLINKMODULE_OPTION_NONE);
	symbol = NSLookupSymbolInModule(module, "_execute");
	function = NSAddressOfSymbol(symbol);

	function();

	NSUnLinkModule(module, NSUNLINKMODULE_OPTION_NONE);
	NSDestroyObjectFileImage(fileImage);
	
	return 0;
}