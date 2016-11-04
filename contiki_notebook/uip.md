## uIP基础 ##

### 几个重要的结构体 ###

- `uip_conn`:

	 		struct uip_conn {
  			uip_ipaddr_t ripaddr;   /**< The IP address of the remote host. */

  			uint16_t lport;        /**< The local TCP port, in network byte order. */

  			uint16_t rport;        /**< The local remote TCP port, in network byte order. */

  			uint8_t rcv_nxt[4];    /**< The sequence number that we expect to receive next. */

  			uint8_t snd_nxt[4];    /**< The sequence number that was last sent by us. */

  			uint16_t len;          /**< Length of the data that was previously sent. */

  			uint16_t mss;          /**< Current maximum segment size for the connection. */

  			uint16_t initialmss;   /**< Initial maximum segment size for the connection. */

  			uint8_t sa;            /**< Retransmission time-out calculation state variable. */

  			uint8_t sv;            /**< Retransmission time-out calculation state variable. */

  			uint8_t rto;           /**< Retransmission time-out. */

  			uint8_t tcpstateflags; /**< TCP state and flags. */

  			uint8_t timer;         /**< The retransmission timer. */

  			uint8_t nrtx;          /**< The number of retransmissions for the lastsegment sent. */

  			uip_tcp_appstate_t appstate; /** The application state. */
	};

- `uip_udp_conn`:

		struct uip_udp_conn {
  		uip_ipaddr_t ripaddr;   /**< The IP address of the remote peer. */

  		uint16_t lport;        /**< The local port number in network byte order. */

  		uint16_t rport;        /**< The remote port number in network byte order. */

  		uint8_t  ttl;          /**< Default time-to-live. */

  		/** The application state. */
  		uip_udp_appstate_t appstate;
		};

- `tcpip_uipstate`:

		struct tcpip_uipstate {
  			struct process *p;
  			void *state;
			};

- `几个重要的宏定义`:

		#define UIP_APPCALL tcpip_uipcall   
		#define UIP_UDP_APPCALL tcpip_uipcall
		#define UIP_ICMP6_APPCALL tcpip_icmp6_call

		typedef struct tcpip_uipstate uip_udp_appstate_t;
		typedef struct tcpip_uipstate uip_tcp_appstate_t;
		typedef struct tcpip_uipstate uip_icmp6_appstate_t;
