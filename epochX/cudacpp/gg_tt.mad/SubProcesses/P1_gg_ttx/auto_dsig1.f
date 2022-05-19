      DOUBLE PRECISION FUNCTION DSIG1(PP,WGT,IMODE)
C     ****************************************************
C     
C     Generated by MadGraph5_aMC@NLO v. 3.3.1_lo_vect, 2022-01-30
C     By the MadGraph5_aMC@NLO Development Team
C     Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
C     
C     Process: g g > t t~ WEIGHTED<=2 @1
C     
C     RETURNS DIFFERENTIAL CROSS SECTION
C     Input:
C     pp    4 momentum of external particles
C     wgt   weight from Monte Carlo
C     imode 0 run, 1 init, 2 reweight, 
C     3 finalize, 4 only PDFs,
C     5 squared amplitude only (never
C     generate events)
C     Output:
C     Amplitude squared and summed
C     ****************************************************
      IMPLICIT NONE
C     
C     CONSTANTS
C     
      INCLUDE 'genps.inc'
      INCLUDE 'nexternal.inc'
      INCLUDE 'maxconfigs.inc'
      INCLUDE 'maxamps.inc'
      DOUBLE PRECISION       CONV
      PARAMETER (CONV=389379.66*1000)  !CONV TO PICOBARNS
      REAL*8     PI
      PARAMETER (PI=3.1415926D0)
C     
C     ARGUMENTS 
C     
      DOUBLE PRECISION PP(0:3,NEXTERNAL), WGT
      INTEGER IMODE
C     
C     LOCAL VARIABLES 
C     
      INTEGER I,ITYPE,LP,IPROC
      DOUBLE PRECISION G1
      DOUBLE PRECISION G2
      DOUBLE PRECISION XPQ(-7:7),PD(0:MAXPROC)
      DOUBLE PRECISION DSIGUU,R,RCONF

      INTEGER LUN,ICONF,IFACT,NFACT
      DATA NFACT/1/
      SAVE NFACT
C     
C     STUFF FOR DRESSED EE COLLISIONS
C     
      INCLUDE '../../Source/PDF/eepdf.inc'
      DOUBLE PRECISION EE_COMP_PROD

      INTEGER I_EE
C     
C     EXTERNAL FUNCTIONS
C     
      LOGICAL PASSCUTS
      DOUBLE PRECISION ALPHAS2,REWGT,PDG2PDF,CUSTOM_BIAS
      INTEGER NEXTUNOPEN
C     
C     GLOBAL VARIABLES
C     
      INTEGER          IPSEL
      COMMON /SUBPROC/ IPSEL
C     MINCFIG has this config number
      INTEGER           MINCFIG, MAXCFIG
      COMMON/TO_CONFIGS/MINCFIG, MAXCFIG
      INTEGER MAPCONFIG(0:LMAXCONFIGS), ICONFIG
      COMMON/TO_MCONFIGS/MAPCONFIG, ICONFIG
C     Keep track of whether cuts already calculated for this event
      LOGICAL CUTSDONE,CUTSPASSED
      COMMON/TO_CUTSDONE/CUTSDONE,CUTSPASSED

      INTEGER SUBDIAG(MAXSPROC),IB(2)
      COMMON/TO_SUB_DIAG/SUBDIAG,IB
      INCLUDE 'coupl.inc'
      INCLUDE 'run.inc'
C     Common blocks
      CHARACTER*7         PDLABEL,EPA_LABEL
      INTEGER       LHAID
      COMMON/TO_PDF/LHAID,PDLABEL,EPA_LABEL
C     
C     local
C     
      DOUBLE PRECISION P1(0:3, NEXTERNAL)

C     
C     DATA
C     
      DATA G1/1*1D0/
      DATA G2/1*1D0/
C     ----------
C     BEGIN CODE
C     ----------
      DSIG1=0D0

      IF(IMODE.EQ.1)THEN
C       Set up process information from file symfact
        LUN=NEXTUNOPEN()
        NFACT=1
        OPEN(UNIT=LUN,FILE='../symfact.dat',STATUS='OLD',ERR=20)
        DO WHILE(.TRUE.)
          READ(LUN,*,ERR=10,END=10) RCONF, IFACT
          ICONF=INT(RCONF)
          IF(ICONF.EQ.MAPCONFIG(MINCFIG))THEN
            NFACT=IFACT
          ENDIF
        ENDDO
        DSIG1 = NFACT
 10     CLOSE(LUN)
        RETURN
 20     WRITE(*,*)'Error opening symfact.dat. No symmetry factor used.'
        RETURN
      ENDIF
C     Continue only if IMODE is 0, 4 or 5
      IF(IMODE.NE.0.AND.IMODE.NE.4.AND.IMODE.NE.5) RETURN


      IF (ABS(LPP(IB(1))).GE.1) THEN
          !LP=SIGN(1,LPP(IB(1)))
        G1=PDG2PDF(LPP(IB(1)),0, IB(1),XBK(IB(1)),DSQRT(Q2FACT(IB(1))))
      ENDIF
      IF (ABS(LPP(IB(2))).GE.1) THEN
          !LP=SIGN(1,LPP(IB(2)))
        G2=PDG2PDF(LPP(IB(2)),0, IB(2),XBK(IB(2)),DSQRT(Q2FACT(IB(2))))
      ENDIF
      PD(0) = 0D0
      IPROC = 0
      IPROC=IPROC+1  ! g g > t t~
      PD(IPROC)=G1*G2
      PD(0)=PD(0)+DABS(PD(IPROC))
      IF (IMODE.EQ.4)THEN
        DSIG1 = PD(0)
        RETURN
      ENDIF
      IF(FRAME_ID.NE.6)THEN
        CALL BOOST_TO_FRAME(PP, FRAME_ID, P1)
      ELSE
        P1 = PP
      ENDIF
C     CALL SMATRIX1(P1,DSIGUU,1)
      STOP 1  ! why is this called?
      IF (IMODE.EQ.5) THEN
        IF (DSIGUU.LT.1D199) THEN
          DSIG1 = DSIGUU*CONV
        ELSE
          DSIG1 = 0.0D0
        ENDIF
        RETURN
      ENDIF
C     Select a flavor combination (need to do here for right sign)
      CALL RANMAR(R)
      IPSEL=0
      DO WHILE (R.GE.0D0 .AND. IPSEL.LT.IPROC)
        IPSEL=IPSEL+1
        R=R-DABS(PD(IPSEL))/PD(0)
      ENDDO

      DSIGUU=DSIGUU*REWGT(PP)

C     Apply the bias weight specified in the run card (default is 1.0)
      DSIGUU=DSIGUU*CUSTOM_BIAS(PP,DSIGUU,1,1)

      DSIGUU=DSIGUU*NFACT

      IF (DSIGUU.LT.1D199) THEN
C       Set sign of dsig based on sign of PDF and matrix element
        DSIG1=DSIGN(CONV*PD(0)*DSIGUU,DSIGUU*PD(IPSEL))
      ELSE
        WRITE(*,*) 'Error in matrix element'
        DSIGUU=0D0
        DSIG1=0D0
      ENDIF
C     Generate events only if IMODE is 0.
      IF(IMODE.EQ.0.AND.DABS(DSIG1).GT.0D0)THEN
C       Call UNWGT to unweight and store events
        CALL UNWGT(PP,DSIG1*WGT,1,1)
      ENDIF

      END
C     
C     Functionality to handling grid
C     



      DOUBLE PRECISION FUNCTION DSIG1_VEC(ALL_PP, ALL_XBK, ALL_Q2FACT,
     $  ALL_CM_RAP, ALL_WGT,IMODE, ALL_OUT)
C     ****************************************************
C     
C     Generated by MadGraph5_aMC@NLO v. 3.3.1_lo_vect, 2022-01-30
C     By the MadGraph5_aMC@NLO Development Team
C     Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
C     
C     Process: g g > t t~ WEIGHTED<=2 @1
C     
C     RETURNS DIFFERENTIAL CROSS SECTION
C     Input:
C     pp    4 momentum of external particles
C     wgt   weight from Monte Carlo
C     imode 0 run, 1 init, 2 reweight, 
C     3 finalize, 4 only PDFs,
C     5 squared amplitude only (never
C     generate events)
C     Output:
C     Amplitude squared and summed
C     ****************************************************
      IMPLICIT NONE
C     
C     CONSTANTS
C     
      INCLUDE '../../Source/vector.inc'
      INCLUDE 'genps.inc'
      INCLUDE 'nexternal.inc'
      INCLUDE 'maxconfigs.inc'
      INCLUDE 'maxamps.inc'
      DOUBLE PRECISION       CONV
      PARAMETER (CONV=389379.66*1000)  !CONV TO PICOBARNS
      REAL*8     PI
      PARAMETER (PI=3.1415926D0)
C     
C     ARGUMENTS 
C     
      DOUBLE PRECISION ALL_PP(0:3,NEXTERNAL,NB_PAGE_MAX)
      DOUBLE PRECISION ALL_WGT(NB_PAGE_MAX)
      DOUBLE PRECISION ALL_XBK(2,NB_PAGE_MAX)
      DOUBLE PRECISION ALL_Q2FACT(2,NB_PAGE_MAX)
      DOUBLE PRECISION ALL_CM_RAP(NB_PAGE_MAX)
      INTEGER IMODE
      DOUBLE PRECISION ALL_OUT(NB_PAGE_MAX)
C     ----------
C     BEGIN CODE
C     ----------
C     
C     LOCAL VARIABLES 
C     
      INTEGER I,ITYPE,LP,IPROC
      DOUBLE PRECISION G1(NB_PAGE_MAX)
      DOUBLE PRECISION G2(NB_PAGE_MAX)
      DOUBLE PRECISION XPQ(-7:7),PD(0:MAXPROC)
      DOUBLE PRECISION ALL_PD(0:MAXPROC, NB_PAGE_MAX)
      DOUBLE PRECISION DSIGUU,R,RCONF
      INTEGER LUN,ICONF,IFACT,NFACT
      DATA NFACT/1/
      SAVE NFACT
      DOUBLE PRECISION RHEL  ! random number
      INTEGER CHANNEL
C     
C     STUFF FOR DRESSED EE COLLISIONS --even if not supported for now--
C     
      INCLUDE '../../Source/PDF/eepdf.inc'
      DOUBLE PRECISION EE_COMP_PROD

      INTEGER I_EE
C     
C     EXTERNAL FUNCTIONS
C     
      LOGICAL PASSCUTS
      DOUBLE PRECISION ALPHAS2,REWGT,PDG2PDF,CUSTOM_BIAS
      INTEGER NEXTUNOPEN
      DOUBLE PRECISION DSIG1
C     
C     GLOBAL VARIABLES
C     
      INTEGER          IPSEL
      COMMON /SUBPROC/ IPSEL
C     MINCFIG has this config number
      INTEGER           MINCFIG, MAXCFIG
      COMMON/TO_CONFIGS/MINCFIG, MAXCFIG
      INTEGER MAPCONFIG(0:LMAXCONFIGS), ICONFIG
      COMMON/TO_MCONFIGS/MAPCONFIG, ICONFIG
C     Keep track of whether cuts already calculated for this event
      LOGICAL CUTSDONE,CUTSPASSED
      COMMON/TO_CUTSDONE/CUTSDONE,CUTSPASSED
C     jamp2 information      
      DOUBLE PRECISION JAMP2(0:MAXFLOW, NB_PAGE_MAX)
      COMMON/TO_JAMPS/       JAMP2

      INTEGER SUBDIAG(MAXSPROC),IB(2)
      COMMON/TO_SUB_DIAG/SUBDIAG,IB
      INCLUDE 'coupl.inc'
      INCLUDE 'run.inc'

      DOUBLE PRECISION P_MULTI(0:3, NEXTERNAL, NB_PAGE_MAX)
      DOUBLE PRECISION HEL_RAND(NB_PAGE_MAX)
      INTEGER SELECTED_HEL(NB_PAGE_MAX)

C     Common blocks
      CHARACTER*7         PDLABEL,EPA_LABEL
      INTEGER       LHAID
      COMMON/TO_PDF/LHAID,PDLABEL,EPA_LABEL

C     
C     local
C     
      DOUBLE PRECISION P1(0:3, NEXTERNAL)
      INTEGER IVEC

C     
C     DATA
C     

C     ----------
C     BEGIN CODE
C     ----------

      IF(IMODE.EQ.1)THEN
        NFACT = DSIG1(ALL_PP(0,1,1), ALL_WGT(1), IMODE)
        RETURN
      ENDIF

C     Continue only if IMODE is 0, 4 or 5
      IF(IMODE.NE.0.AND.IMODE.NE.4.AND.IMODE.NE.5) RETURN


      DO IVEC=1,NB_PAGE_LOOP
        IF (ABS(LPP(IB(1))).GE.1) THEN
            !LP=SIGN(1,LPP(IB(1)))
          G1(IVEC)=PDG2PDF(LPP(IB(1)),0, IB(1),ALL_XBK(IB(1),IVEC)
     $     ,DSQRT(ALL_Q2FACT(IB(1), IVEC)))
        ENDIF
        IF (ABS(LPP(IB(2))).GE.1) THEN
            !LP=SIGN(1,LPP(IB(2)))
          G2(IVEC)=PDG2PDF(LPP(IB(2)),0, IB(2),ALL_XBK(IB(2),IVEC)
     $     ,DSQRT(ALL_Q2FACT(IB(2), IVEC)))
        ENDIF
      ENDDO
      ALL_PD(0,:) = 0D0
      IPROC = 0
      IPROC=IPROC+1  ! g g > t t~
      DO IVEC=1, NB_PAGE_LOOP
        ALL_PD(IPROC,IVEC)=G1(IVEC)*G2(IVEC)
        ALL_PD(0,IVEC)=ALL_PD(0,IVEC)+DABS(ALL_PD(IPROC,IVEC))

      ENDDO


      IF (IMODE.EQ.4)THEN
        ALL_OUT(:) = ALL_PD(0,:)
        RETURN
      ENDIF

      DO IVEC=1,NB_PAGE_LOOP
C       Do not need those three here do I?	 
        XBK(:) = ALL_XBK(:,IVEC)
C       CM_RAP = ALL_CM_RAP(IVEC)
        Q2FACT(:) = ALL_Q2FACT(:, IVEC)

        IF(FRAME_ID.NE.6)THEN
          CALL BOOST_TO_FRAME(ALL_PP(0,1,IVEC), FRAME_ID, P_MULTI(0,1
     $     ,IVEC))
        ELSE
          P_MULTI(:,:,IVEC) = ALL_PP(:,:,IVEC)
        ENDIF
        CALL RANMAR(HEL_RAND(IVEC))
C       CALL SMATRIX1(P1, RHEL, channel, ALL_OUT(IVEC), JAMP2(0,
C        IVEC), IVEC)
      ENDDO
      CHANNEL = SUBDIAG(1)

C     do IVEC=1, NB_PAGE_LOOP
C     CALL SMATRIX1(p_multi(0,1,IVEC), hel_rand(ivec), channel,
C      ALL_OUT(IVEC), JAMP2(0, IVEC), IVEC)
C     enddo 
      CALL SMATRIX1_MULTI(P_MULTI, HEL_RAND,  CHANNEL, ALL_OUT ,
     $  SELECTED_HEL, JAMP2)


      DO IVEC=1,NB_PAGE_LOOP
        DSIGUU = ALL_OUT(IVEC)
        IF (IMODE.EQ.5) THEN
          IF (DSIGUU.LT.1D199) THEN
            ALL_OUT(IVEC) = DSIGUU*CONV
          ELSE
            ALL_OUT(IVEC) = 0.0D0
          ENDIF
          RETURN
        ENDIF
C       Select a flavor combination (need to do here for right sign)
        CALL RANMAR(R)
        IPSEL=0
        DO WHILE (R.GE.0D0 .AND. IPSEL.LT.IPROC)
          IPSEL=IPSEL+1
          R=R-DABS(ALL_PD(IPSEL,IVEC))/ALL_PD(0,IVEC)
        ENDDO

        XBK(:) = ALL_XBK(:,IVEC)
C       CM_RAP = ALL_CM_RAP(IVEC)
        Q2FACT(:) = ALL_Q2FACT(:, IVEC)

        IF(FRAME_ID.NE.6)THEN
          CALL BOOST_TO_FRAME(ALL_PP(0,1,IVEC), FRAME_ID, P1)
        ELSE
          P1 = ALL_PP(:,:,IVEC)
        ENDIF
        CALL RESTORE_CL_VAL_TO(IVEC)
        DSIGUU=DSIGUU*REWGT(P1)

C       Apply the bias weight specified in the run card (default is
C        1.0)
        DSIGUU=DSIGUU*CUSTOM_BIAS(P1,DSIGUU,1, IVEC)

        DSIGUU=DSIGUU*NFACT

        IF (DSIGUU.LT.1D199) THEN
C         Set sign of dsig based on sign of PDF and matrix element
          ALL_OUT(IVEC)=DSIGN(CONV*ALL_PD(0,IVEC)*DSIGUU,DSIGUU
     $     *ALL_PD(IPSEL,IVEC))
        ELSE
          WRITE(*,*) 'Error in matrix element'
          DSIGUU=0D0
          ALL_OUT(IVEC)=0D0
        ENDIF
C       Generate events only if IMODE is 0.
        IF(IMODE.EQ.0.AND.DABS(ALL_OUT(IVEC)).GT.0D0)THEN
C         Call UNWGT to unweight and store events
          CALL UNWGT(ALL_PP(0,1,IVEC), ALL_OUT(IVEC)*ALL_WGT(IVEC),1,
     $      IVEC)
        ENDIF
      ENDDO

      END
C     
C     Functionality to handling grid
C     






      SUBROUTINE PRINT_ZERO_AMP1()

      RETURN
      END


      SUBROUTINE SMATRIX1_MULTI(P_MULTI, HEL_RAND,  CHANNEL, OUT ,
     $  SELECTED_HEL, JAMP2_MULTI)

      USE OMP_LIB

      INCLUDE 'nexternal.inc'
      INCLUDE '../../Source/vector.inc'
      INCLUDE 'maxamps.inc'
      DOUBLE PRECISION P_MULTI(0:3, NEXTERNAL, NB_PAGE_MAX)
      DOUBLE PRECISION HEL_RAND(NB_PAGE_MAX)
      INTEGER CHANNEL
      DOUBLE PRECISION OUT(NB_PAGE_MAX)
      INTEGER SELECTED_HEL(NB_PAGE_MAX)
      DOUBLE PRECISION JAMP2_MULTI(0:MAXFLOW, NB_PAGE_MAX)

      INTEGER IVEC


!$OMP PARALLEL
!$OMP DO
      DO IVEC=1, NB_PAGE_LOOP
        CALL SMATRIX1(P_MULTI(0,1,IVEC),
     &	                         hel_rand(IVEC),
     &				 channel,
     &				 out(IVEC),
C       &				 selected_hel(IVEC),
     &				 jamp2_multi(0,IVEC),
     &				 IVEC
     &				 )
      ENDDO
!$OMP END DO
!$OMP END PARALLEL
      RETURN
      END

      INTEGER FUNCTION GET_NHEL1(HEL, IPART)
C     if hel>0 return the helicity of particule ipart for the selected
C      helicity configuration
C     if hel=0 return the number of helicity state possible for that
C      particle 
      IMPLICIT NONE
      INTEGER HEL,I, IPART
      INCLUDE 'nexternal.inc'
      INTEGER ONE_NHEL(NEXTERNAL)
      INTEGER                 NCOMB
      PARAMETER (             NCOMB=16)
      INTEGER NHEL(NEXTERNAL,0:NCOMB)
      DATA (NHEL(I,0),I=1,4) / 2, 2, 2, 2/
      DATA (NHEL(I,   1),I=1,4) /-1,-1,-1, 1/
      DATA (NHEL(I,   2),I=1,4) /-1,-1,-1,-1/
      DATA (NHEL(I,   3),I=1,4) /-1,-1, 1, 1/
      DATA (NHEL(I,   4),I=1,4) /-1,-1, 1,-1/
      DATA (NHEL(I,   5),I=1,4) /-1, 1,-1, 1/
      DATA (NHEL(I,   6),I=1,4) /-1, 1,-1,-1/
      DATA (NHEL(I,   7),I=1,4) /-1, 1, 1, 1/
      DATA (NHEL(I,   8),I=1,4) /-1, 1, 1,-1/
      DATA (NHEL(I,   9),I=1,4) / 1,-1,-1, 1/
      DATA (NHEL(I,  10),I=1,4) / 1,-1,-1,-1/
      DATA (NHEL(I,  11),I=1,4) / 1,-1, 1, 1/
      DATA (NHEL(I,  12),I=1,4) / 1,-1, 1,-1/
      DATA (NHEL(I,  13),I=1,4) / 1, 1,-1, 1/
      DATA (NHEL(I,  14),I=1,4) / 1, 1,-1,-1/
      DATA (NHEL(I,  15),I=1,4) / 1, 1, 1, 1/
      DATA (NHEL(I,  16),I=1,4) / 1, 1, 1,-1/

      GET_NHEL1 = NHEL(IPART, IABS(HEL))
      RETURN
      END


