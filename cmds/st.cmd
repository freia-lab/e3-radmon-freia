# This should be a test or example startup script

require dpu

iocshLoad("$(dpu_DIR)/dpu.iocsh", "ASYN_PORT_NAME=PORT1, DPU_IP='192.168.10.5', DPU_PORT=4001,DPU_PREFIX=XX-")

