/*----------------------------------------------------------------------------
 * File:  Unit_Testing_Unit_Testing_IPC_bridge.c
 *
 * Description:
 * Methods for bridging to an external entity.
 *
 * External Entity:  Inter_Process_Communication (Unit_Test_IPC)
 * 
 * Copyright 2017 John Törnblom
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *--------------------------------------------------------------------------*/
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "Unit_Testing_Unit_Testing_IPC_bridge.h"


/*
 * Bridge:  Fork
 */
i_t
Unit_Testing_Unit_Testing_IPC_Fork()
{
  return fork();
}


/*
 * Bridge:  Send_Message
 */
bool
Unit_Testing_Unit_Testing_IPC_Send_Message( const i_t p_fd, const i_t p_type, c_t p_value[ESCHER_SYS_MAX_STRING_LEN] )
{
  size_t length = sizeof(i_t);
  if(write(p_fd, &p_type, length) != length) {
    return false;
  }

  length = strlen(p_value);
  if(write(p_fd, &length, sizeof(size_t)) != sizeof(size_t)) {
    return false;
  }

  if(write(p_fd, p_value, length) != length) {
    return false;
  }
  
  return true;
}


/*
 * Bridge:  Receive_Message
 */
bool
Unit_Testing_Unit_Testing_IPC_Receive_Message( const i_t p_fd, i_t * p_type, c_t p_value[ESCHER_SYS_MAX_STRING_LEN] )
{
  size_t length = sizeof(i_t);
  if(read(p_fd, p_type, length) != length) {
    return false;
  }
  
  if(read(p_fd, &length, sizeof(size_t)) != sizeof(size_t)) {
    return false;
  }
  
  if(read(p_fd, p_value, length) != length) {
    return false;
  }
  
  p_value[length] = '\0';
  return true;
}


/*
 * Bridge:  Pipe
 */
void
Unit_Testing_Unit_Testing_IPC_Pipe( i_t * p_read_fd, i_t * p_write_fd )
{
  int pipefd[2];
  if(pipe(pipefd) == 0) {
    *p_read_fd = pipefd[0];
    *p_write_fd = pipefd[1];
  }
}


/*
 * Bridge:  Close
 */
void
Unit_Testing_Unit_Testing_IPC_Close( const i_t p_fd )
{
  close(p_fd);
}


/*
 * Bridge:  Wait
 */
bool
Unit_Testing_Unit_Testing_IPC_Wait( const i_t p_process_id )
{
  int status;
  waitpid(p_process_id, &status, 0);
  return WIFEXITED(status);
}


/*
 * Bridge:  Exit
 */
void
Unit_Testing_Unit_Testing_IPC_Exit()
{
  exit(0);
}


/*
 * Bridge:  Get_Process_Id
 */
i_t
Unit_Testing_Unit_Testing_IPC_Get_Process_Id()
{
  return getpid();
}
