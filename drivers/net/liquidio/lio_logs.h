/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright(c) 2017 Cavium, Inc
 */

#ifndef _LIO_LOGS_H_
#define _LIO_LOGS_H_

#define lio_dev_printf(lio_dev, level, fmt, args...)			\
	RTE_LOG(level, PMD, "%s" fmt, (lio_dev)->dev_string, ##args)

#define lio_dev_info(lio_dev, fmt, args...)				\
	lio_dev_printf(lio_dev, INFO, "INFO: " fmt, ##args)

#define lio_dev_err(lio_dev, fmt, args...)				\
	lio_dev_printf(lio_dev, ERR, "ERROR: %s() " fmt, __func__, ##args)

#define PMD_INIT_LOG(level, fmt, args...) RTE_LOG(level, PMD, fmt, ## args)

/* Enable these through config options */

#ifdef RTE_LIBRTE_LIO_DEBUG_INIT
#define PMD_INIT_FUNC_TRACE() PMD_INIT_LOG(DEBUG, "%s() >>\n", __func__)
#else /* !RTE_LIBRTE_LIO_DEBUG_INIT */
#define PMD_INIT_FUNC_TRACE() do { } while (0)
#endif /* RTE_LIBRTE_LIO_DEBUG_INIT */

#ifdef RTE_LIBRTE_LIO_DEBUG_DRIVER
#define lio_dev_dbg(lio_dev, fmt, args...)				\
	lio_dev_printf(lio_dev, DEBUG, "DEBUG: %s() " fmt, __func__, ##args)
#else /* !RTE_LIBRTE_LIO_DEBUG_DRIVER */
#define lio_dev_dbg(lio_dev, fmt, args...) do { } while (0)
#endif /* RTE_LIBRTE_LIO_DEBUG_DRIVER */

#ifdef RTE_LIBRTE_LIO_DEBUG_RX
#define PMD_RX_LOG(lio_dev, level, fmt, args...)			\
	lio_dev_printf(lio_dev, level, "RX: %s() " fmt, __func__, ##args)
#else /* !RTE_LIBRTE_LIO_DEBUG_RX */
#define PMD_RX_LOG(lio_dev, level, fmt, args...) do { } while (0)
#endif /* RTE_LIBRTE_LIO_DEBUG_RX */

#ifdef RTE_LIBRTE_LIO_DEBUG_TX
#define PMD_TX_LOG(lio_dev, level, fmt, args...)			\
	lio_dev_printf(lio_dev, level, "TX: %s() " fmt, __func__, ##args)
#else /* !RTE_LIBRTE_LIO_DEBUG_TX */
#define PMD_TX_LOG(lio_dev, level, fmt, args...) do { } while (0)
#endif /* RTE_LIBRTE_LIO_DEBUG_TX */

#ifdef RTE_LIBRTE_LIO_DEBUG_MBOX
#define PMD_MBOX_LOG(lio_dev, level, fmt, args...)			\
	lio_dev_printf(lio_dev, level, "MBOX: %s() " fmt, __func__, ##args)
#else /* !RTE_LIBRTE_LIO_DEBUG_MBOX */
#define PMD_MBOX_LOG(level, fmt, args...) do { } while (0)
#endif /* RTE_LIBRTE_LIO_DEBUG_MBOX */

#ifdef RTE_LIBRTE_LIO_DEBUG_REGS
#define PMD_REGS_LOG(lio_dev, fmt, args...)				\
	lio_dev_printf(lio_dev, DEBUG, "REGS: " fmt, ##args)
#else /* !RTE_LIBRTE_LIO_DEBUG_REGS */
#define PMD_REGS_LOG(level, fmt, args...) do { } while (0)
#endif /* RTE_LIBRTE_LIO_DEBUG_REGS */

#endif  /* _LIO_LOGS_H_ */
