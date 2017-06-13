/*
* Copyright 2017, Data61
* Commonwealth Scientific and Industrial Research Organisation (CSIRO)
* ABN 41 687 119 230.
* This software may be distributed and modified according to the terms of
* the BSD 2-Clause license. Note that NO WARRANTY is provided.
* See "LICENSE_BSD2.txt" for details.
* @TAG(D61_BSD)
*/
#include <sel4arm-vmm/plat/device_map.h>
#include <sel4arm-vmm/devices.h>


static int handle_waypoint_fault(struct device* d, vm_t* vm, fault_t* fault){
//    vusb_device_t* vusb;
//    usb_ctrl_regs_t *ctrl_regs;
//    uint32_t* reg;
//    int offset;
//
//    assert(d->priv);
//    offset = fault_get_address(fault) - d->pstart - 0x1000;
//    vusb = device_to_vusb_dev_data(d);
//    ctrl_regs = vusb->ctrl_regs;
//    reg = (uint32_t*)((void*)ctrl_regs + (offset & ~0x3));
//    if (fault_is_read(fault)) {
//        if (reg != &ctrl_regs->status) {
//            fault_set_data(fault, *reg);
//        }
//    } else {
//        if (reg == &ctrl_regs->status) {
//            /* start a transfer */
//            root_hub_ctrl_start(vusb->hcd, ctrl_regs);
//        } else if (reg == &ctrl_regs->intr) {
//            /* Clear the interrupt pending flag */
//            *reg = fault_emulate(fault, *reg);
//        } else if (reg == &ctrl_regs->notify) {
//            /* Manual notification */
//            vm_vusb_notify(vusb);
//        } else if (reg == &ctrl_regs->cancel_transaction) {
//            /* Manual notification */
//            vm_vusb_cancel(vusb, fault_get_data(fault));
//        } else if ((void*)reg >= (void*)&ctrl_regs->req) {
//            /* Fill out the root hub USB request */
//            *reg = fault_emulate(fault, *reg);
//        }
//    }   
//    return advance_fault(fault);
    printf("VM RECEIVED FAULT\n");
    return ignore_fault(fault);
}

const struct device dev_uxas_waypoint = {
    .devid = DEV_CUSTOM,
    .name = "waypoint",
    .pstart = 0xE0000000, //this is an empty address on the tk1
    .size = 0x1000,
    .handle_page_fault = handle_waypoint_fault,
    .priv = NULL
};

const struct device dev_usb1 = {
    .devid = DEV_CUSTOM,
    .name = "usb3",
    .pstart = USB1_PADDR,
    .size = 0x1000,
    .handle_page_fault = NULL,
    .priv = NULL
};


const struct device dev_usb3 = {
    .devid = DEV_CUSTOM,
    .name = "usb3",
    .pstart = USB3_PADDR,
    .size = 0x1000,
    .handle_page_fault = NULL,
    .priv = NULL
};

const struct device dev_sdmmc = {
    .devid = DEV_CUSTOM,
    .name = "usb3",
    .pstart = SDMMC_PADDR,
    .size = 0x1000,
    .handle_page_fault = NULL,
    .priv = NULL
};

const struct device dev_rtc_kbc_pmc = {
    .devid = DEV_CUSTOM,
    .name = "rtc_kbc_pmc",
    .pstart = RTC_PADDR,
    .size = 0x1000,
    .handle_page_fault = NULL,
    .priv = NULL
};

const struct device dev_data_memory = {
    .devid = DEV_CUSTOM,
    .name = "data_memory",
    .pstart = DATA_MEMORY_PADDR,
    .size = 0x1000,
    .handle_page_fault = NULL,
    .priv = NULL
};

const struct device dev_exception_vectors = {
    .devid = DEV_CUSTOM,
    .name = "exception_vectors",
    .pstart = EXCEPTION_VECTORS_PADDR,
    .size = 0x1000,
    .handle_page_fault = NULL,
    .priv = NULL
};

const struct device dev_system_registers = {
    .devid = DEV_CUSTOM,
    .name = "system_registers",
    .pstart = SYSTEM_REGISTERS_PADDR,
    .size = 0x1000,
    .handle_page_fault = NULL,
    .priv = NULL
};

const struct device dev_ictlr = {
    .devid = DEV_CUSTOM,
    .name = "ictlr",
    .pstart = ICTLR_PADDR,
    .size = 0x1000,
    .handle_page_fault = NULL,
    .priv = NULL
};

const struct device dev_apb_misc = {
    .devid = DEV_CUSTOM,
    .name = "apb_misc",
    .pstart = APB_MISC_PADDR,
    .size = 0x1000,
    .handle_page_fault = NULL,
    .priv = NULL
};

const struct device dev_fuse = {
    .devid = DEV_CUSTOM,
    .name = "fuse",
    .pstart = FUSE_PADDR,
    .size = 0x1000,
    .handle_page_fault = NULL,
    .priv = NULL
};

const struct device dev_gpios = {
    .devid = DEV_CUSTOM,
    .name = "gpios",
    .pstart = GPIOS_PADDR,
    .size = 0x1000,
    .handle_page_fault = NULL,
    .priv = NULL
};
