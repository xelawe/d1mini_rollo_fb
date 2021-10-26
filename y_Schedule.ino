void do_sched_1s() {
  gv_1s = true;
  gv_1m_cnt += 1;
  if ( gv_1m_cnt >= 60 ) {
    gv_1m = true;
    gv_1m_cnt = 0;
  }

}

void init_sched() {
  sched_1s.attach(1, do_sched_1s);
}
