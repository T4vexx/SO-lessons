// Lista de registradores que vão salvar e restaurar o stado de um processo

struct context {
	int eip;
	int esp;
	int eax;
	int ebx;
	int ecx;
	int edx;
	int esi;
	int edi;
	int ebp;
};

// Diferentes estados que um processo pode ter 

enum proc_state {
	UNUSED,
	EMBRYO,
	SLEEPING,
	RUNNABLE,
	RUNNING,
	ZOMBIE
};

// Aqui fica todas as informações dos processos
// Incluindo seu registro de contexto e estado

struct process {
	char *mem;			//Start of process memory
	uint sz;			//Size of process memory
	char *kstack;			//Bottom of kernel stack or this process

	enum proc_state state;		//Process state
	int pid;			//Process id
	struct proc *parent;		//Parent process
	void *chan;			//If !zero, sleeping on chan
	int killed; 			//If !zero, has been killed
	struct file *ofile[NOFILE];	//Open files
	struct inode *cws;		//Current directory
	struct context context;		//Switch here to run process
	struct trapframe *tf;		//Trap frame for the current interrupt
};
