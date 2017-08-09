/*----------------------------------------------------------------------------
 * File:  Unit_Testing_Unit_Testing_String_Rendering_bridge.c
 *
 * Description:
 * Methods for bridging to an external entity.
 *
 * External Entity:  Unit_Test_String_Rendering (Unit_Test_String_Rendering)
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
#include <string.h>

#include "Unit_Testing_Unit_Testing_String_Rendering_bridge.h"

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))


/*
 * Bridge:  Render_Integer
 */
c_t *
Unit_Testing_Unit_Testing_String_Rendering_Render_Integer( c_t A0xtumlsret[ESCHER_SYS_MAX_STRING_LEN], const i_t p_value )
{
  snprintf(A0xtumlsret, ESCHER_SYS_MAX_STRING_LEN, "%d", p_value);
  return A0xtumlsret;
}


/*
 * Bridge:  Replace
 */
c_t *
Unit_Testing_Unit_Testing_String_Rendering_Replace( c_t res[ESCHER_SYS_MAX_STRING_LEN], c_t new[ESCHER_SYS_MAX_STRING_LEN], c_t old[ESCHER_SYS_MAX_STRING_LEN], c_t str[ESCHER_SYS_MAX_STRING_LEN] )
{
  char *p;
  int i = 0;

  res[0] = '\0';

  do {
    if(!(p=strstr(str, old))) {
      strncat(res, str, MIN(ESCHER_SYS_MAX_STRING_LEN - strlen(res), strlen(str)));
    } else {
      strncat(res, str, MIN(ESCHER_SYS_MAX_STRING_LEN - strlen(res), p-str));
      strncat(res, new, MIN(ESCHER_SYS_MAX_STRING_LEN - strlen(res), strlen(new)));
      str = p + strlen(old);
    }
  } while (p);

  return res;
}


/*
 * Bridge:  Render_ASCII
 */
c_t *
Unit_Testing_Unit_Testing_String_Rendering_Render_ASCII( c_t A0xtumlsret[ESCHER_SYS_MAX_STRING_LEN], const i_t p_code )
{
  snprintf(A0xtumlsret, ESCHER_SYS_MAX_STRING_LEN, "%c", p_code);
  return A0xtumlsret;
}

