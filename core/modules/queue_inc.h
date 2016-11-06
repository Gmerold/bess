#ifndef __QUEUE_INC_H__
#define __QUEUE_INC_H__

#include "../module.h"
#include "../module_msg.pb.h"
#include "../port.h"

class QueueInc : public Module {
 public:
  QueueInc() : Module(), port_(), qid_(), prefetch_(), burst_() {}

  virtual struct snobj *Init(struct snobj *arg);
  virtual pb_error_t Init(const bess::pb::QueueIncArg &arg);
  virtual void Deinit();

  virtual struct task_result RunTask(void *arg);

  virtual std::string GetDesc() const;

  struct snobj *CommandSetBurst(struct snobj *arg);
  bess::pb::ModuleCommandResponse CommandSetBurstPb(
      const bess::pb::QueueIncCommandSetBurstArg &arg);

  static const gate_idx_t kNumIGates = 0;
  static const gate_idx_t kNumOGates = 1;

  static const Commands<Module> cmds;
  static const PbCommands<Module> pb_cmds;

 private:
  Port *port_;
  queue_t qid_;
  int prefetch_;
  int burst_;
  pb_error_t SetBurst(int64_t burst);
};

#endif
