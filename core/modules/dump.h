#ifndef __DUMP_H__
#define __DUMP_H__

#include "../message.h"
#include "../module.h"

class Dump : public Module {
 public:
  virtual struct snobj *Init(struct snobj *arg);
  pb_error_t Init(const bess::pb::DumpArg &arg);

  virtual void ProcessBatch(struct pkt_batch *batch);

  struct snobj *CommandSetInterval(struct snobj *arg);
  bess::pb::ModuleCommandResponse CommandSetIntervalPb(
      const bess::pb::DumpArg &arg);

  static const gate_idx_t kNumIGates = 1;
  static const gate_idx_t kNumOGates = 1;

  static const Commands<Module> cmds;
  static const PbCommands<Module> pb_cmds;

 private:
  uint64_t min_interval_ns_;
  uint64_t next_ns_;
};

#endif
