#ifndef __ISA_H__
#define __ISA_H__

#include _ISA_H_

// monitor
extern char isa_logo[];
void init_isa();

// reg
extern CPU_state cpu;
void isa_reg_display();
word_t isa_reg_str2val(const char *name, bool *success);

// exec
vaddr_t isa_exec_once();

// memory
enum { MEM_TYPE_IFETCH, MEM_TYPE_READ, MEM_TYPE_WRITE };
enum { MEM_RET_OK, MEM_RET_NEED_TRANSLATE, MEM_RET_FAIL, MEM_RET_CROSS_PAGE };
paddr_t isa_mmu_translate(vaddr_t vaddr, int type, int len);
#ifndef isa_vaddr_check
int isa_vaddr_check(vaddr_t vaddr, int type, int len);
#endif

// difftest
  // for dut
bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc);
void isa_difftest_attach();

  // for ref
void isa_difftest_getregs(void *r);
void isa_difftest_setregs(const void *r);
void isa_difftest_raise_intr(word_t NO);

#endif
